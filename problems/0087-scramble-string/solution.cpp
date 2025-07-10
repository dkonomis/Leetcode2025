class Solution {
public:
    /*
    Problem: 0087 - Scramble String

    Given two strings s1 and s2, return true if s2 is a scrambled string of s1.
    A scramble means s2 can be formed by recursively swapping substrings of s1.

    Approach:
    - Use recursion with memoization to check all possible split points.
    - At each step, try:
        1. No swap: s1[0:i] vs s2[0:i] and s1[i:] vs s2[i:]
        2. Swap: s1[0:i] vs s2[-i:] and s1[i:] vs s2[0:-i]
    - Use unordered_map as a memoization cache.
    - Prune with a frequency count to reject impossible matches early.

    Time complexity: O(n^4), due to recursive splitting and memoization.
    Space complexity: O(n^3), for cache and recursion stack.
    */

    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        // Prune early by comparing sorted characters.
        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return memo[key] = false;

        int n = s1.size();
        // Try all possible split points.
        for (int i = 1; i < n; ++i) {
            // Case 1: No swap.
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap.
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};

