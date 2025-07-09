class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        """
        Problem: 0064 - Minimum Path Sum

        Given an m × n grid filled with non-negative integers, find a path from the top-left
        to the bottom-right corner which minimizes the sum of all numbers along the path.
        You may only move either down or right at any point.

        Approach:
        - Use dynamic programming to compute the minimum path sum to each cell.
        - Let dp[i][j] represent the minimum path sum to reach cell (i, j).
        - Initialize the first row and column based on cumulative sums.
        - For all other cells, dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).

        Time complexity: O(m * n)
        Space complexity: O(m * n), can be optimized to O(n) using 1D DP.
        """
        m, n = len(grid), len(grid[0])
        dp = [[0] * n for _ in range(m)]

        # Initialize the top-left cell.
        dp[0][0] = grid[0][0]

        # Fill the first row.
        for j in range(1, n):
            dp[0][j] = dp[0][j - 1] + grid[0][j]

        # Fill the first column.
        for i in range(1, m):
            dp[i][0] = dp[i - 1][0] + grid[i][0]

        # Fill the rest of the grid.
        for i in range(1, m):
            for j in range(1, n):
                # Choose the smaller path from top or left.
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])

        return dp[m - 1][n - 1]

