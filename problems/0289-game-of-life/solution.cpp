class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /**
         * Problem: 0289 - Game of Life
         * 
         * Update the board in-place to the next state according to Conway's
         * Game of Life rules. Uses bit manipulation to store both current
         * and next state in the same cell.
         * 
         * Approach:
         * - Use 2 bits: bit 0 for current state, bit 1 for next state
         * - Count live neighbors for each cell
         * - Apply rules to determine next state
         * - Shift right to move next state to current state
         * 
         * Time complexity: O(m * n) where m, n are board dimensions.
         * Space complexity: O(1) as we modify in-place.
         */
        int m = board.size();
        int n = board[0].size();
        
        // First pass: calculate next state for each cell.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Count live neighbors.
                int live_neighbors = count_live_neighbors(board, i, j, m, n);
                
                // Apply Game of Life rules.
                if (board[i][j] == 1) {  // Currently alive.
                    // Rule 2: Live cell with 2 or 3 neighbors survives.
                    if (live_neighbors == 2 || live_neighbors == 3) {
                        board[i][j] |= 2;  // Set bit 1 to indicate alive in next state.
                    }
                } else {  // Currently dead.
                    // Rule 4: Dead cell with exactly 3 neighbors becomes alive.
                    if (live_neighbors == 3) {
                        board[i][j] |= 2;  // Set bit 1 to indicate alive in next state.
                    }
                }
            }
        }
        
        // Second pass: update board to next state.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;  // Shift right to move next state to current.
            }
        }
    }
    
private:
    int count_live_neighbors(vector<vector<int>>& board, int row, int col, 
                            int m, int n) {
        // Count live neighbors in all 8 directions.
        int count = 0;
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, 
                                            {0, -1}, {0, 1}, 
                                            {1, -1}, {1, 0}, {1, 1}};
        
        for (auto [dx, dy] : directions) {
            int nx = row + dx;
            int ny = col + dy;
            // Check bounds and count if neighbor is currently alive.
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                count += board[nx][ny] & 1;  // Check bit 0 for current state.
            }
        }
        
        return count;
    }
};
