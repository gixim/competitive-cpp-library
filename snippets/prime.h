#ifndef __SNIPPETS_PRIME__
#define __SNIPPETS_PRIME__

#include <cassert>
#include <vector>

// Source:
// https://github.com/gixim/competitive-cpp-library/blob/main/snippets/prime.h
//
// Reference:
// https://atcoder.jp/contests/abc383/editorial/11553
namespace snippets::prime {

// Sieve of Eratosthenes
struct prime {
    std::vector<bool> p;  // p[N]: true if N is a prime number
    std::vector<int> l;  // List of prime numbers

    prime(int n) {
        p.resize(n + 1, true);
        l.clear();

        p[0] = false;
        p[1] = false;
        for (int i = 2; i <= n; i++) {
            if (p[i]) {
                l.push_back(i);
                for (int j = i * 2; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }
    }

    bool is_prime(int n) {
        assert(0 <= n && n < (int)p.size());
        return p[n];
    }
    const std::vector<int>& get_prime_list(void) { return l; }
};

}  // namespace snippets::prime

#endif
