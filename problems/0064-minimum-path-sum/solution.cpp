#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    Problem: 0064 - Minimum Path Sum

    Given an m × n grid filled with non-negative integers, find a path from the top-left
    to the bottom-right corner which minimizes the sum of all numbers along the path.
    You may only move either down or right at any point.

    Approach:
    - Use dynamic programming to store the minimum path sum at each cell.
    - Let dp[i][j] be the minimum path sum to reach cell (i, j).
    - Initialize the first row and first column based on cumulative sums.
    - For all other cells, compute:
        dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).

    Time Complexity: O(m * n)
    Space Complexity: O(m * n), can be reduced to O(n) with 1D optimization.
    */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        // Initialize top-left cell.
        dp[0][0] = grid[0][0];

        // Fill first row.
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill first column.
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the rest of the grid.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // Minimum sum from top or left.
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};

