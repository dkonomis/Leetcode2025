class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /*
        Problem: 0097 - Interleaving String

        Given strings s1, s2, and s3, determine whether s3 is formed by interleaving s1 and s2.
        An interleaving must preserve the character order of both s1 and s2.

        Approach:
        - Use 2D dynamic programming.
        - Let dp[i][j] be true if s3[0..i+j-1] is an interleaving of s1[0..i-1] and s2[0..j-1].
        - Initialize dp[0][0] = true.
        - First row dp[0][j]: only s2 used; match s3[0..j-1] with s2[0..j-1].
        - First column dp[i][0]: only s1 used; match s3[0..i-1] with s1[0..i-1].
        - General case:
            dp[i][j] is true if either:
                - dp[i-1][j] is true and s1[i-1] == s3[i+j-1]
                - dp[i][j-1] is true and s2[j-1] == s3[i+j-1]

        Time complexity: O(m * n).
        Space complexity: O(m * n).
        */
        int m = s1.length(), n = s2.length();

        // If combined lengths don't match, interleaving is impossible.
        if (m + n != s3.length()) {
            return false;
        }

        // Create a (m+1) x (n+1) DP table initialized to false.
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // Initialize first column (only s1 used).
        for (int i = 1; i <= m; ++i) {
            if (s1[i - 1] == s3[i - 1]) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Initialize first row (only s2 used).
        for (int j = 1; j <= n; ++j) {
            if (s2[j - 1] == s3[j - 1]) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill in the rest of the DP table.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Check if current character from s1 matches s3.
                if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                    dp[i][j] = true;
                }

                // Check if current character from s2 matches s3.
                if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};

