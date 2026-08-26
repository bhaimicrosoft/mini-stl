#pragma once

#include "lifetime.hpp"
#include <iterator>
#include <utility>

namespace miniSTL {
    template<typename InputIt, typename ForwardIt>
    ForwardIt uninitialized_copy(
        InputIt first,
        InputIt last,
        ForwardIt dest) {
        ForwardIt current = dest;

        try {
            for (; first != last; ++first, ++current) {
                construct_at(std::addressof(*current), *first);
            }

            return current;
        } catch (...) {
            destroy_range(dest, current);
            throw;
        }
    }

    template<typename InputIt, typename ForwardIt>
    ForwardIt uninitialized_move(
        InputIt first,
        InputIt last,
        ForwardIt dest) {
        ForwardIt current = dest;

        try {
            for (; first != last; ++first, ++current) {
                construct_at(std::addressof(*current), std::move(*first));
            }

            return current;
        } catch (...) {
            destroy_range(dest, current);
            throw;
        }
    }
}
