#pragma once

#include <new>
#include <utility>
#include <memory>

namespace miniSTL {
    template<typename T, typename... Args>
    constexpr T *construct_at(T *ptr, Args &&... args) {
        return ::new(static_cast<void *>(ptr))T(std::forward<Args>(args)...);
    }

    template<typename T>
    constexpr void destroy_at(T *ptr) {
        ptr->~T();
    }

    template<typename ForwardIt>
    constexpr void destroy_range(ForwardIt first,
                                 ForwardIt last) {
        while (first != last) {
            destroy_at(std::addressof(*first));
            ++first;
        }
    }
}
