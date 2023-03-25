#pragma once

#include <functional>
#include <string>
#include <ostream>
#include <array>

namespace util {
    template<class T, size_t N>
    std::string to_string(const std::array<T, N> &array, std::function<std::string(T)> to_string);

    template<class T, size_t N>
    std::string to_string(const std::array<T, N> &array);

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

    template<typename T, size_t CURRENT_SIZE, size_t NEW_SIZE, size_t FROM = 0>
    std::array<T, NEW_SIZE> copy_resize(const std::array<T, CURRENT_SIZE>& array);

    template<size_t C>
    std::array<char, C> convert_type(const std::array<std::uint8_t, C>& array);


    template<typename T, size_t PACKET_SIZE, size_t DATA_SIZE, size_t RESULT_SIZE, size_t OFFSET>
    std::array<T, RESULT_SIZE> batch_create(const std::array<std::uint8_t, PACKET_SIZE>& bytes);
}
