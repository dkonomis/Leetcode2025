class Solution {
public:
    /*
    Problem: 0072 - Edit Distance

    Given two strings word1 and word2, return the minimum number of operations
    required to convert word1 to word2. Allowed operations: insert, delete, replace.

    Approach:
    - Use bottom-up dynamic programming.
    - Let dp[i][j] represent the minimum number of operations to convert
      word1[0..i-1] to word2[0..j-1].
    - Build the table using recurrence:
        if word1[i-1] == word2[j-1]:
            dp[i][j] = dp[i-1][j-1]
        else:
            dp[i][j] = 1 + min(
                dp[i-1][j],    // delete
                dp[i][j-1],    // insert
                dp[i-1][j-1]   // replace
            )

    Time Complexity: O(m * n), where m = word1.size(), n = word2.size()
    Space Complexity: O(m * n)
    */
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize base cases: converting from or to an empty string.
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;  // Delete all characters from word1.
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;  // Insert all characters to word1.
        }

        // Fill the DP table based on character matches and edit operations.
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // Characters match, no edit needed.
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // Delete from word1.
                        dp[i][j - 1],    // Insert into word1.
                        dp[i - 1][j - 1] // Replace in word1.
                    });
                }
            }
        }

        return dp[m][n];
    }
};

