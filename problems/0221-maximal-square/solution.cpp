class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /**
         * Problem: 0221 - Maximal Square
         * 
         * Find the largest square of 1's in a binary matrix.
         * Use dynamic programming where dp[i][j] represents the side length
         * of the largest square with bottom-right corner at (i, j).
         * 
         * Time complexity: O(m * n) where m and n are matrix dimensions.
         * Space complexity: O(n) using optimized 1D DP array.
         */
        
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Use 1D DP array to save space.
        // dp[j] represents the largest square ending at current row, column j.
        vector<int> dp(n, 0);
        int max_side = 0;
        int prev = 0;  // Stores dp[i-1][j-1] value.
        
        // Process each cell in the matrix.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Save current dp[j] before updating (will be prev for next iteration).
                int temp = dp[j];
                
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // First row or column: can only form square of size 1.
                        dp[j] = 1;
                    } else {
                        // Current cell can extend the square from three directions:
                        // 1. dp[j] (before update) = dp[i-1][j] - square above
                        // 2. dp[j-1] = dp[i][j-1] - square to the left  
                        // 3. prev = dp[i-1][j-1] - square diagonally above-left
                        // Take minimum and add 1 for current cell.
                        dp[j] = min({dp[j], dp[j-1], prev}) + 1;
                    }
                    
                    // Update maximum square side length found.
                    max_side = max(max_side, dp[j]);
                } else {
                    // Current cell is '0', cannot form square here.
                    dp[j] = 0;
                }
                
                // Update prev for next column.
                prev = temp;
            }
        }
        
        // Return area of the largest square.
        return max_side * max_side;
    }
};
