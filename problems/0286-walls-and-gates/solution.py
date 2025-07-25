class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Problem: 0286 - Walls and Gates
        
        Fill each empty room with the distance to its nearest gate using
        multi-source BFS. Start BFS from all gates simultaneously to ensure
        each room gets the shortest distance to any gate.
        
        Approach:
        - Find all gates (0s) and add them to queue
        - BFS from all gates simultaneously, level by level
        - First time we reach an empty room is the shortest distance
        - Update room value and continue BFS from that room
        
        Time complexity: O(m * n) where m, n are grid dimensions.
        Space complexity: O(m * n) for the queue in worst case.
        """
        if not rooms or not rooms[0]:
            return
        
        m, n = len(rooms), len(rooms[0])
        INF = 2147483647
        queue = deque()
        
        # Find all gates and add to queue.
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    queue.append((i, j))
        
        # BFS from all gates simultaneously.
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while queue:
            x, y = queue.popleft()
            
            # Check all 4 directions.
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                
                # If valid cell and is an empty room.
                if (0 <= nx < m and 0 <= ny < n and 
                    rooms[nx][ny] == INF):
                    # Update distance and add to queue.
                    rooms[nx][ny] = rooms[x][y] + 1
                    queue.append((nx, ny))
