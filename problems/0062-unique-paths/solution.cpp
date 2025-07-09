#include <vector>
using namespace std;

class Solution {
public:
    /*
    Problem: 0062 - Unique Paths

    A robot is located at the top-left corner of an m × n grid. The robot can only move
    either right or down at each step. Return the number of unique paths to reach the
    bottom-right corner of the grid.

    Approach:
    - Use bottom-up dynamic programming.
    - Let dp[i][j] store the number of unique paths to reach cell (i, j).
    - Initialize all cells in the first row and first column to 1 (only one way to reach them).
    - For all other cells, compute: dp[i][j] = dp[i-1][j] + dp[i][j-1].

    Time Complexity: O(m * n)
    Space Complexity: O(m * n), can be optimized to O(n) using 1D DP.
    */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));  // Initialize dp table with 1s.

        // Fill the table row by row.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // From top + from left.
            }
        }

        return dp[m - 1][n - 1];  // Return number of paths to bottom-right.
    }
};

