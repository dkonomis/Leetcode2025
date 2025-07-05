#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        /*
        Problem 0010 – Regular Expression Matching.

        dp[i][j] == true ⇔ the suffix s[i:] matches the suffix p[j:].
        We fill the table from the end of the strings toward the front.

        Time Complexity  : O(m × n),  m = |s|, n = |p|.
        Space Complexity : O(m × n).
        */

        int m = static_cast<int>(s.size());
        int n = static_cast<int>(p.size());

        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[m][n] = true;                                     // empty string vs. empty pattern.

        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {               // j == n already initialised.
                bool firstMatch = (i < m) &&
                                   (p[j] == s[i] || p[j] == '.');

                if (j + 1 < n && p[j + 1] == '*') {          // pattern has “x*”.
                    bool zeroOcc  = dp[i][j + 2];             // skip “x*”.
                    bool oneOrMore = firstMatch && dp[i + 1][j]; // consume one char of s.
                    dp[i][j] = zeroOcc || oneOrMore;
                } else {                                      // ordinary single-character match.
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

