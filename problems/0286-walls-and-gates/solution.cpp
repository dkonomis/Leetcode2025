class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        /**
         * Problem: 0286 - Walls and Gates
         * 
         * Fill each empty room with the distance to its nearest gate using
         * multi-source BFS. Start BFS from all gates simultaneously to ensure
         * each room gets the shortest distance to any gate.
         * 
         * Approach:
         * - Find all gates (0s) and add them to queue
         * - BFS from all gates simultaneously, level by level
         * - First time we reach an empty room is the shortest distance
         * - Update room value and continue BFS from that room
         * 
         * Time complexity: O(m * n) where m, n are grid dimensions.
         * Space complexity: O(m * n) for the queue in worst case.
         */
        if (rooms.empty() || rooms[0].empty()) {
            return;
        }
        
        int m = rooms.size();
        int n = rooms[0].size();
        const int INF = 2147483647;
        queue<pair<int, int>> q;
        
        // Find all gates and add to queue.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // BFS from all gates simultaneously.
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Check all 4 directions.
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                // If valid cell and is an empty room.
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    rooms[nx][ny] == INF) {
                    // Update distance and add to queue.
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
