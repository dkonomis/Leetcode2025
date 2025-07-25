class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        """
        Problem: 0296 - Best Meeting Point
        
        Find the optimal meeting point that minimizes total Manhattan distance
        for all friends (1s in the grid).
        
        Approach: The optimal meeting point is at the median of all row coordinates
        and the median of all column coordinates. This works because Manhattan distance
        separates into independent row and column distances, and median minimizes
        the sum of absolute deviations in 1D.
        
        Time complexity: O(mn), where m and n are grid dimensions.
        Space complexity: O(p), where p is the number of people (1s in grid).
        """
        rows = []
        cols = []
        
        # Collect row indices (already sorted due to iteration order).
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    rows.append(i)
        
        # Collect column indices (sorted by iterating columns first).
        for j in range(len(grid[0])):
            for i in range(len(grid)):
                if grid[i][j] == 1:
                    cols.append(j)
        
        # Find median positions.
        median_row = rows[len(rows) // 2]
        median_col = cols[len(cols) // 2]
        
        # Calculate total Manhattan distance to median point.
        res = 0
        for row in rows:
            res += abs(row - median_row)
        for col in cols:
            res += abs(col - median_col)
        
        return res
