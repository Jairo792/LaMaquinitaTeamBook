/*
 * Bit Hacks
 * Useful techniques for working with bit masks.
 * Widely used in competitive programming for set problems, DP with bitmasks, combinatorics, etc.
 */

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

/*
 * next_bits_permutation(x)
 * Returns the next mask with the same number of set bits (1s) in lexicographical order.
 * Useful for generating all combinations of k elements as bit masks.
 *
 * Example:
 * x = 0b00111 (represents a combination of 3 elements)
 * next_bits_permutation(x) -> 0b01011, then 0b01101, etc.
 */
ull next_bits_permutation(ull x) {
    ull c = __builtin_ctzll(x);         // Count trailing zeros in x
    ull r = x + (1ULL << c);            // Add 1 to the least significant set bit
    return (r ^ x) >> (c + 2) | r;      // Calculate the next permutation
}

/*
 * subsets(s)
 * Iterates over all proper subsets (does not include s) of a given set s.
 * The set s is represented as a bit mask.
 *
 * Example:
 * s = 0b1011 (set {0,1,3})
 * Will iterate over subsets: 1010, 1001, 1000, 0011, 0010, 0001
 */
void subsets(ull s) {
    for (ull x = s; x;) {
        --x &= s;
        // You can work with each subset x here
        // For example, print it:
        // cout << bitset<4>(x) << '\n';
    }
}

