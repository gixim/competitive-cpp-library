#ifndef __SNIPPETS_TIMEKEEPER__
#define __SNIPPETS_TIMEKEEPER__

#include <chrono>

// Source:
// https://github.com/gixim/competitive-cpp-library/blob/main/snippets/timekeeper.h
namespace snippets::timekeeper {

struct time_keeper {
    std::chrono::steady_clock::time_point start_time;

    void start() { start_time = std::chrono::steady_clock::now(); }

    long long passed_ms(void) const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::steady_clock::now() - start_time)
            .count();
    }

    bool is_over(long long milliseconds) const {
        return passed_ms() >= milliseconds;
    }
};

}  // namespace snippets::timekeeper

#endif
