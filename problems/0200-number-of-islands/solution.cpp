class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
         * Problem: 0200 - Number of Islands
         * Given a 2D grid of '1's (land) and '0's (water), count number of islands.
         * An island is formed by connecting adjacent lands horizontally or vertically.
         * 
         * Approach: Use DFS to explore each connected component. When we find an
         * unvisited '1', start DFS to mark all connected land as visited.
         * 
         * Time complexity: O(m * n) where m is rows and n is columns.
         * Space complexity: O(m * n) for DFS recursion stack in worst case.
         */
        
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        
        // Iterate through each cell in the grid.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If we find unvisited land, start DFS for new island.
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, rows, cols);
                    islands++;  // Found a new island.
                }
            }
        }
        
        return islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int row, int col, int rows, int cols) {
        // Base case: out of bounds or water or already visited.
        if (row < 0 || row >= rows || 
            col < 0 || col >= cols || 
            grid[row][col] != '1') {
            return;
        }
        
        // Mark current cell as visited by setting it to '0'.
        grid[row][col] = '0';
        
        // Explore all 4 adjacent directions recursively.
        dfs(grid, row + 1, col, rows, cols);  // down.
        dfs(grid, row - 1, col, rows, cols);  // up.
        dfs(grid, row, col + 1, rows, cols);  // right.
        dfs(grid, row, col - 1, rows, cols);  // left.
    }
};
