class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
        Problem: 0240 - Search a 2D Matrix II
        
        Search for target in a matrix sorted row-wise and column-wise.
        Start from top-right corner (or bottom-left).
        If current element > target, move left (smaller values).
        If current element < target, move down (larger values).
        This eliminates one row or column at each step.
        
        Time complexity: O(m + n) where m is rows and n is columns.
        Space complexity: O(1).
        """
        if not matrix or not matrix[0]:
            return False
        
        m, n = len(matrix), len(matrix[0])
        
        # Start from top-right corner.
        row = 0
        col = n - 1
        
        # Search until we go out of bounds.
        while row < m and col >= 0:
            if matrix[row][col] == target:
                # Found the target.
                return True
            elif matrix[row][col] > target:
                # Current element too large, move left.
                col -= 1
            else:
                # Current element too small, move down.
                row += 1
        
        # Target not found.
        return False
