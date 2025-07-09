#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
    Problem: 0060 - Permutation Sequence

    Given two integers n and k, return the k-th permutation of the sequence [1, 2, ..., n]
    in lexicographic order.

    Approach:
    - Precompute factorials from 0! to n!.
    - Use a vector to hold the digits [1..n] that can be selected.
    - Convert k to 0-based index for easier block calculations.
    - For each position from n-1 to 0:
        - Determine the index in digits by k // fact[i].
        - Append that digit to the result and erase it from the list.
        - Update k = k % fact[i].

    Time Complexity: O(n^2), due to vector erase at arbitrary index.
    Space Complexity: O(n), for factorial array and digit list.
    */
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);  // fact[i] = i!
        vector<int> digits(n);       // available digits: [1, 2, ..., n]

        // Precompute factorials and initialize digit list.
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
            digits[i - 1] = i;
        }

        --k;  // convert to 0-based index
        string res;

        // Build the permutation digit by digit.
        for (int i = n - 1; i >= 0; --i) {
            int idx = k / fact[i];              // choose idx-th available digit
            k %= fact[i];                       // update k for next iteration
            res += to_string(digits[idx]);      // append digit to result
            digits.erase(digits.begin() + idx); // remove used digit
        }

        return res;
    }
};

