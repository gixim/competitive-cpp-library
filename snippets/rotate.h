#ifndef __SNIPPETS_ROTATE__
#define __SNIPPETS_ROTATE__

#include <cassert>
#include <string>
#include <vector>

// Source:
// https://github.com/gixim/competitive-cpp-library/blob/main/snippets/rotate.h
namespace snippets::rotate {

template <typename T>
std::vector<std::vector<T>> rotate_right(const std::vector<std::vector<T>>& a) {
    assert(!a.empty());

    const std::size_t h = a.size();
    const std::size_t w = a.front().size();

    assert(w != 0);
    for (const auto& row : a) {
        assert(row.size() == w);
    }

    std::vector<std::vector<T>> ret(w, std::vector<T>(h));

    for (std::size_t i = 0; i < h; ++i) {
        for (std::size_t j = 0; j < w; ++j) {
            ret[j][h - 1 - i] = a[i][j];
        }
    }

    return ret;
}

template <typename T>
std::vector<std::vector<T>> rotate_left(const std::vector<std::vector<T>>& a) {
    assert(!a.empty());

    const std::size_t h = a.size();
    const std::size_t w = a.front().size();

    assert(w != 0);
    for (const auto& row : a) {
        assert(row.size() == w);
    }

    std::vector<std::vector<T>> ret(w, std::vector<T>(h));

    for (std::size_t i = 0; i < h; ++i) {
        for (std::size_t j = 0; j < w; ++j) {
            ret[w - 1 - j][i] = a[i][j];
        }
    }

    return ret;
}

inline std::vector<std::string> rotate_right(
    const std::vector<std::string>& a) {
    assert(!a.empty());

    const std::size_t h = a.size();
    const std::size_t w = a.front().size();

    assert(w != 0);
    for (const auto& row : a) {
        assert(row.size() == w);
    }

    std::vector<std::string> ret(w, std::string(h, ' '));

    for (std::size_t i = 0; i < h; ++i) {
        for (std::size_t j = 0; j < w; ++j) {
            ret[j][h - 1 - i] = a[i][j];
        }
    }

    return ret;
}

inline std::vector<std::string> rotate_left(const std::vector<std::string>& a) {
    assert(!a.empty());

    const std::size_t h = a.size();
    const std::size_t w = a.front().size();

    assert(w != 0);
    for (const auto& row : a) {
        assert(row.size() == w);
    }

    std::vector<std::string> ret(w, std::string(h, ' '));

    for (std::size_t i = 0; i < h; ++i) {
        for (std::size_t j = 0; j < w; ++j) {
            ret[w - 1 - j][i] = a[i][j];
        }
    }

    return ret;
}

}  // namespace snippets::rotate

#endif
