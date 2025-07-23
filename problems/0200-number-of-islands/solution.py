class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        Problem: 0200 - Number of Islands
        
        Given a 2D grid of '1's (land) and '0's (water), count number of islands.
        An island is formed by connecting adjacent lands horizontally or vertically.
        
        Approach: Use DFS to explore each connected component. When we find an
        unvisited '1', start DFS to mark all connected land as visited.
        
        Time complexity: O(m * n) where m is rows and n is columns.
        Space complexity: O(m * n) for DFS recursion stack in worst case.
        """
        if not grid or not grid[0]:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up.
        islands = 0
        
        def dfs(row, col):
            """DFS to mark all connected land cells as visited."""
            # Base case: out of bounds or water or already visited.
            if (row < 0 or row >= rows or 
                col < 0 or col >= cols or 
                grid[row][col] != '1'):
                return
            
            # Mark current cell as visited by setting it to '0'.
            grid[row][col] = '0'
            
            # Explore all 4 adjacent directions recursively.
            for dr, dc in directions:
                dfs(row + dr, col + dc)
        
        # Iterate through each cell in the grid.
        for i in range(rows):
            for j in range(cols):
                # If we find unvisited land, start DFS for new island.
                if grid[i][j] == '1':
                    dfs(i, j)
                    islands += 1  # Found a new island.
        
        return islands
