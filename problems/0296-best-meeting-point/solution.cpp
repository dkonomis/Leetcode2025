class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        /**
         * Problem: 0296 - Best Meeting Point
         * 
         * Find the optimal meeting point that minimizes total Manhattan distance
         * for all friends (1s in the grid).
         * 
         * Approach: The optimal meeting point is at the median of all row coordinates
         * and the median of all column coordinates. We cleverly avoid sorting by
         * collecting rows and columns in sorted order through our iteration pattern.
         * Rows are naturally sorted by iterating row-first. Columns are sorted by
         * iterating with column as the outer loop.
         * 
         * Time complexity: O(mn), where m and n are grid dimensions.
         * Space complexity: O(p), where p is the number of people (1s in grid).
         */
        
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows;
        vector<int> cols;
        
        // Collect row indices (already sorted due to iteration order).
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                }
            }
        }
        
        // Collect column indices (sorted by iterating columns first).
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    cols.push_back(j);
                }
            }
        }
        
        // Find median positions.
        int median_row = rows[rows.size() / 2];
        int median_col = cols[cols.size() / 2];
        
        // Calculate total Manhattan distance to median point.
        int res = 0;
        for (int row : rows) {
            res += abs(row - median_row);
        }
        for (int col : cols) {
            res += abs(col - median_col);
        }
        
        return res;
    }
};
