#ifndef __SNIPPETS_GRIDS__
#define __SNIPPETS_GRIDS__

#include <utility>

// Source:
// https://github.com/gixim/competitive-cpp-library/blob/main/snippets/grids.h
namespace snippets::grids {

struct direction_string {
    int y;
    int x;
    char s;  // Forward direction
    char r;  // Backward direction
};

// clang-format off
[[maybe_unused]] constexpr std::pair<int, int> d8[] = {
    {0, 1},    //  R /  E
    {-1, 1},   // UR / NE
    {-1, 0},   // U  / N
    {-1, -1},  // UL / NW
    {0, -1},   //  L /  W
    {1, -1},   // DL / SW
    {1, 0},    // D  / S
    {1, 1},    // DR / SE
};

[[maybe_unused]] constexpr std::pair<int, int> d4[] = {
    {0, 1},   // R / E
    {-1, 0},  // U / N
    {0, -1},  // L / W
    {1, 0},   // D / S
};

[[maybe_unused]] constexpr direction_string d4str[] {
    {0, 1, 'R', 'L'},
    {-1, 0, 'U', 'D'},
    {0, -1, 'L', 'R'},
    {1, 0, 'D', 'U'},
};
// clang-format on

template <typename T>
inline bool is_inside(T y, T x, T h, T w) {
    if (y < 0 || h <= y || x < 0 || w <= x) {
        return false;
    }
    return true;
}

}  // namespace snippets::grids

#endif
