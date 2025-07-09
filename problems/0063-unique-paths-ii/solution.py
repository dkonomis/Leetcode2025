class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        """
        Problem: 0063 - Unique Paths II

        A robot is located at the top-left corner of an m × n grid with obstacles.
        The robot can only move either right or down at any point. Return the number
        of unique paths to the bottom-right corner, avoiding obstacles.

        Approach:
        - Use dynamic programming.
        - Let dp[i][j] be the number of unique paths to reach cell (i, j).
        - If obstacleGrid[i][j] == 1, then dp[i][j] = 0 (cell is blocked).
        - Otherwise, dp[i][j] = dp[i-1][j] + dp[i][j-1].
        - Handle the first row and column separately to account for early obstacles.

        Time complexity: O(m * n)
        Space complexity: O(m * n), can be optimized to O(n) if needed.
        """
        if not obstacleGrid or obstacleGrid[0][0] == 1:
            return 0  # No path if starting cell is blocked.

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1  # Start point.

        # Fill first column.
        for i in range(1, m):
            if obstacleGrid[i][0] == 0:
                dp[i][0] = dp[i - 1][0]

        # Fill first row.
        for j in range(1, n):
            if obstacleGrid[0][j] == 0:
                dp[0][j] = dp[0][j - 1]

        # Fill the rest of the grid.
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    # If the current cell is not an obstacle, sum paths from top and left.
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m - 1][n - 1]

