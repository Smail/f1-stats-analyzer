#pragma once

#include <functional>
#include <string>
#include <ostream>

namespace util {
    template<class T, size_t N>
    std::string to_string(const std::array<T, N> array, std::function<std::string(T)> to_string) {
        std::string result = "[";

        for (size_t i = 0; i < N - 1; ++i) {
            result += to_string(array[i]) + ", ";
        }
        result += to_string(array[N - 1]) + "]";

        return result;
    }

    template<class T, size_t N>
    std::string to_string(const std::array<T, N> array) {
        std::string result = "[";

        for (size_t i = 0; i < N - 1; ++i) {
            result += std::to_string(array[i]) + ", ";
        }
        result += std::to_string(array[N - 1]) + "]";

        return result;
    }
}
