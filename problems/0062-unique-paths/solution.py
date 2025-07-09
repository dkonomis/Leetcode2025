class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
        Problem: 0062 - Unique Paths

        A robot is located at the top-left corner of an m × n grid. The robot can only move
        either right or down at each step. Return the number of unique paths to reach the
        bottom-right corner of the grid.

        Approach:
        - Use bottom-up dynamic programming.
        - Let dp[i][j] be the number of unique paths to reach cell (i, j).
        - Initialize the first row and first column with 1s (only one way to reach those).
        - For all other cells, dp[i][j] = dp[i-1][j] + dp[i][j-1].

        Time complexity: O(m * n)
        Space complexity: O(m * n), can be reduced to O(n) with 1D DP.
        """
        dp = [[1] * n for _ in range(m)]  # Initialize dp table with 1s.

        # Fill the table row by row.
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]  # From top + from left.

        return dp[m - 1][n - 1]  # Number of unique paths to bottom-right corner.

