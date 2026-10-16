#ifndef __SNIPPETS_GRIDS__
#define __SNIPPETS_GRIDS__

#include <algorithm>
#include <cassert>
#include <string>

// Source:
// https://github.com/gixim/competitive-cpp-library/blob/main/snippets/grids.h
namespace snippets::base {

template <typename T>
inline std::string to_base(T n, int base) {
    assert(2 <= base && base <= 36);

    constexpr std::string_view digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (n == 0) {
        return "0";
    }

    std::string s;
    bool neg = n < 0;

    do {
        int rem = n % base;
        if (rem < 0) {
            rem = -rem;
        }
        s += digits[rem];
        n /= base;
    } while (n != 0);

    if (neg) {
        s += '-';
    }

    std::reverse(s.begin(), s.end());
    return s;
}

}  // namespace snippets::base

#endif
