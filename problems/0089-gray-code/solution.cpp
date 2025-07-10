class Solution {
public:
    /*
    Problem: 0089 - Gray Code

    Given a non-negative integer n, generate a sequence of 2^n integers
    representing the Gray code. A Gray code sequence has the property that
    successive numbers differ by exactly one bit.

    Approach:
    - Start with the base case: n = 0 → sequence = {0}.
    - For each i from 1 to n:
        * Reflect the current list.
        * Prefix each number in the reflected part with a 1 at bit position (i-1),
          which is done by bitwise OR with (1 << (i - 1)).
        * Append these new values to the original list.

    This construction ensures adjacent values differ by exactly one bit,
    and the first and last values also differ by one bit.

    Time complexity: O(2^n)
    Space complexity: O(2^n)
    */
    vector<int> grayCode(int n) {
        vector<int> res = {0};  // Base case for n = 0.

        for (int i = 0; i < n; ++i) {
            int bit = 1 << i;  // Bitmask to set the i-th bit.

            // Reflect and prefix the current sequence.
            for (int j = res.size() - 1; j >= 0; --j) {
                res.push_back(res[j] | bit);  // Add new value with the current bit set.
            }
        }

        return res;
    }
};

