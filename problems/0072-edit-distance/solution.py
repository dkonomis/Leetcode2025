class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        """
        Problem: 0072 - Edit Distance

        Given two strings word1 and word2, return the minimum number of operations
        required to convert word1 to word2. Allowed operations: insert, delete, replace.

        Approach:
        - Use bottom-up dynamic programming.
        - Let dp[i][j] represent the minimum number of operations to convert
          word1[0:i] to word2[0:j].
        - Build the table using recurrence:
            if word1[i-1] == word2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(
                    dp[i-1][j],    # delete
                    dp[i][j-1],    # insert
                    dp[i-1][j-1]   # replace
                )

        Time complexity: O(m * n), where m = len(word1), n = len(word2)
        Space complexity: O(m * n)
        """
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # Initialize base cases: converting from/to empty string.
        for i in range(m + 1):
            dp[i][0] = i  # Deleting all characters from word1.
        for j in range(n + 1):
            dp[0][j] = j  # Inserting all characters into word1.

        # Fill the DP table based on character matches and operations.
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]  # Characters match, no cost.
                else:
                    dp[i][j] = 1 + min(
                        dp[i - 1][j],    # Delete from word1.
                        dp[i][j - 1],    # Insert into word1.
                        dp[i - 1][j - 1] # Replace in word1.
                    )

        return dp[m][n]

