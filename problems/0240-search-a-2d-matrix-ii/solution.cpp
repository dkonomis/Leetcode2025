class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * Problem: 0240 - Search a 2D Matrix II
         * 
         * Search for target in a matrix sorted row-wise and column-wise.
         * Start from top-right corner (or bottom-left).
         * If current element > target, move left (smaller values).
         * If current element < target, move down (larger values).
         * This eliminates one row or column at each step.
         * 
         * Time complexity: O(m + n) where m is rows and n is columns.
         * Space complexity: O(1).
         */
        
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Start from top-right corner.
        int row = 0;
        int col = n - 1;
        
        // Search until we go out of bounds.
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                // Found the target.
                return true;
            } else if (matrix[row][col] > target) {
                // Current element too large, move left.
                col--;
            } else {
                // Current element too small, move down.
                row++;
            }
        }
        
        // Target not found.
        return false;
    }
};
