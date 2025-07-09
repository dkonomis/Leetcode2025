#include <vector>
using namespace std;

class Solution {
public:
    /*
    Problem: 0063 - Unique Paths II

    A robot is located at the top-left corner of an m × n grid with obstacles.
    The robot can only move either right or down at any point. Return the number
    of unique paths to the bottom-right corner, avoiding obstacles.

    Approach:
    - Use dynamic programming.
    - Let dp[i][j] be the number of unique paths to reach cell (i, j).
    - If obstacleGrid[i][j] == 1, then dp[i][j] = 0 (cell is blocked).
    - Otherwise, dp[i][j] = dp[i-1][j] + dp[i][j-1].
    - Initialize the first row and column carefully to respect obstacle positions.

    Time Complexity: O(m * n)
    Space Complexity: O(m * n), can be optimized to O(n) with 1D DP.
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) {
            return 0;  // No path if starting cell is blocked.
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;  // Start position.

        // Fill first column.
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill first row.
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the rest of the grid.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    // If cell is not an obstacle, sum paths from top and left.
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

