class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        Problem: 0130 - Surrounded Regions
        
        Capture all regions surrounded by 'X' by flipping 'O' to 'X'.
        
        Approach:
        1. Find all 'O's connected to borders (these cannot be captured).
        2. Use BFS from all border 'O's to mark connected regions as safe.
        3. Flip all remaining 'O's to 'X' (these are truly surrounded).
        4. Restore safe regions back to 'O'.
        
        Time complexity: O(m * n) where m and n are board dimensions.
        Space complexity: O(m * n) for the queue in worst case.
        */
        
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        
        // Find all border 'O's and add them to queue.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Check if cell is on border and contains 'O'.
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = 'T';  // Mark as temporarily safe.
                }
            }
        }
        
        // BFS to mark all 'O's connected to border as safe.
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            // Check all 4 directions.
            for (auto [dr, dc] : directions) {
                int new_row = row + dr;
                int new_col = col + dc;
                
                // Check bounds and if neighbor is 'O'.
                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && 
                    board[new_row][new_col] == 'O') {
                    board[new_row][new_col] = 'T';  // Mark as safe.
                    q.push({new_row, new_col});
                }
            }
        }
        
        // Final pass: flip 'O' to 'X' (surrounded) and 'T' back to 'O' (safe).
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Surrounded region.
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';  // Border-connected region.
                }
            }
        }
    }
};
