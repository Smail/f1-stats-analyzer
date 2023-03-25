#pragma once

#include <functional>
#include <string>
#include <ostream>
#include <array>

namespace util {
    template<typename T>
    constexpr T convert(const std::array<std::uint8_t, sizeof(T)>& bytes) {
        T result{0};
        for (int i = 0; i < bytes.size(); ++i) result |= static_cast<T>(bytes[i]) << (i * 8);
        return result;
    }

    template<>
    constexpr float convert(const std::array<std::uint8_t, sizeof(float)>& bytes) {
        return std::bit_cast<float>(convert<std::uint32_t>(bytes));
    }

    template<>
    constexpr double convert(const std::array<std::uint8_t, sizeof(double)>& bytes) {
        return std::bit_cast<double>(convert<std::uint64_t>(bytes));
    }

    template<class T, size_t N>
    std::string to_string(const std::array<T, N>& array, std::function<std::string(T)> to_string) {
        std::string result = "[";

        for (size_t i = 0; i < N - 1; ++i) {
            result += to_string(array[i]) + ", ";
        }
        result += to_string(array[N - 1]) + "]";

        return result;
    }

    template<class T, size_t N>
    std::string to_string(const std::array<T, N>& array) {
        std::string result = "[";

        for (size_t i = 0; i < N - 1; ++i) {
            result += std::to_string(array[i]) + ", ";
        }
        result += std::to_string(array[N - 1]) + "]";

        return result;
    }

    template<typename T, size_t CURRENT_SIZE, size_t NEW_SIZE, size_t FROM = 0>
    std::array<T, NEW_SIZE> copy_resize(const std::array<T, CURRENT_SIZE>& array) {
        std::array<T, NEW_SIZE> result{};

        std::copy_n(array.cbegin() + FROM, NEW_SIZE, result.begin());

        return result;
    }

    template<size_t C>
    std::array<char, C> convert_type(const std::array<std::uint8_t, C>& array) {
        return (const std::array<char, 48>&) array;
    }

    template<typename T, size_t PACKET_SIZE, size_t DATA_SIZE, size_t RESULT_SIZE, size_t OFFSET>
    std::array<T, RESULT_SIZE> batch_create(const std::array<std::uint8_t, PACKET_SIZE>& bytes) {
        std::array<T, RESULT_SIZE> result{};

        for (size_t i = 0; i < RESULT_SIZE; ++i) {
            std::array<std::uint8_t, DATA_SIZE> xs{};
            std::copy_n(bytes.cbegin() + i * DATA_SIZE + OFFSET, DATA_SIZE, xs.begin());
            // result[i] = T{util::copy_resize<std::uint8_t, PACKET_SIZE, DATA_SIZE, i * DATA_SIZE + OFFSET>(bytes)};
            result[i] = T{xs};
        }

        return result;
    }
}
