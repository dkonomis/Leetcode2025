#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*
        Problem: 0005 - Longest Palindromic Substring.

        Approach:
        - Use dynamic programming to fill a table where dp[left][right] is true if s[left..right] is a palindrome.
        - Initialize all single-character and two-character palindromes.
        - Expand to longer substrings from the bottom up.

        Time Complexity: O(n^2), where n is the length of the string.
        Space Complexity: O(n^2), for the dp table.
        */

        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int max_length = 0;
        string res = "";

        // All substrings of length 1 are palindromes.
        for (int left = 0; left < n; ++left) {
            dp[left][left] = true;
            if (left != n - 1 && s[left] == s[left + 1]) {
                dp[left][left + 1] = true;
            }
        }

        // Check substrings of length ≥ 3.
        for (int left = n - 3; left >= 0; --left) {
            for (int right = left + 2; right < n; ++right) {
                if (s[left] == s[right] && dp[left + 1][right - 1]) {
                    dp[left][right] = true;
                }
            }
        }

        // Find the longest palindromic substring.
        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                if (dp[left][right] && (right - left + 1 > max_length)) {
                    max_length = right - left + 1;
                    res = s.substr(left, max_length);
                }
            }
        }

        return res;
    }
};

