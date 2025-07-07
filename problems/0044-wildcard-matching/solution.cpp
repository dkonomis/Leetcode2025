// 0044. Wildcard Matching

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        /*
        0044. Wildcard Matching

        Problem:
        Implement wildcard pattern matching with support for '?' and '*'.
        - '?' matches any single character.
        - '*' matches any sequence of characters (including empty).
        The entire string must match the pattern.

        Approach:
        Use dynamic programming:
        - dp[i][j] = whether s[0..i-1] matches p[0..j-1].
        - Initialize dp[0][0] = true (empty string matches empty pattern).
        - If p[j-1] == '*', then dp[0][j] = dp[0][j-1] since '*' can match empty.

        Transition:
        - If p[j-1] == '*':
            dp[i][j] = dp[i][j-1] or dp[i-1][j]
        - If p[j-1] == '?' or p[j-1] == s[i-1]:
            dp[i][j] = dp[i-1][j-1]

        Time complexity: O(m * n), where m = s.length(), n = p.length().
        Space complexity: O(m * n), can be optimized to O(n).
        */

        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;  // Empty string matches empty pattern.

        // Initialize dp[0][j]: only '*' can match empty string.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the dp table.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // '*' matches zero characters (dp[i][j-1]) or one more character (dp[i-1][j]).
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // Exact match or single wildcard match.
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

