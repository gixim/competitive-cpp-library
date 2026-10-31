#ifndef __SNIPPETS_ARGSORT__
#define __SNIPPETS_ARGSORT__

#include <algorithm>
#include <vector>

// Source:
// https://github.com/gixim/competitive-cpp-library/blob/main/snippets/argsort.h
//
// Reference:
// https://atcoder.jp/contests/abc442/editorial/15136
namespace snippets::argsort {

struct point {
    long long x;
    long long y;
};

inline long long cross_product(const point& a, const point& b) {
    return (a.x * b.y) - (a.y * b.x);
}

inline bool cmp_rot_left(const point& a, const point& b) {
    long long ah = ((a.y < 0) || ((a.y == 0) && (a.x < 0))) ? 1 : 0;
    long long bh = ((b.y < 0) || ((b.y == 0) && (b.x < 0))) ? 1 : 0;
    if (ah != bh) {
        return ah < bh;
    }
    return cross_product(a, b) > 0;
}

inline bool cmp_rot_right(const point& a, const point& b) {
    return !cmp_rot_left(a, b);
}

inline void argument_sort(std::vector<point>& points, bool clockwise = false) {
    auto cmp_func = (clockwise) ? cmp_rot_right : cmp_rot_left;
    std::sort(points.begin(), points.end(), cmp_func);
}

}  // namespace snippets::argsort

#endif
