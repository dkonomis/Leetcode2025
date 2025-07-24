class Vector2D:
    def __init__(self, vec: List[List[int]]):
        """
        Problem: 0251 - Flatten 2D Vector
        
        Design an iterator to flatten a 2D vector. Track current position
        using row index (i) and column index (j). Skip empty lists by
        advancing indices in the forward() helper method.
        
        Time complexity: O(1) amortized for both next() and hasNext().
        Space complexity: O(1) excluding input storage.
        """
        self.vec = vec
        self.i = 0  # Current row index.
        self.j = 0  # Current column index.
    
    def next(self) -> int:
        # Ensure we're at a valid position.
        self.hasNext()
        # Get current element and advance column index.
        res = self.vec[self.i][self.j]
        self.j += 1
        return res
    
    def hasNext(self) -> bool:
        # Advance to next valid position if needed.
        self._forward()
        # Check if we still have elements.
        return self.i < len(self.vec)
    
    def _forward(self):
        # Skip empty lists and advance to next valid position.
        while self.i < len(self.vec) and self.j >= len(self.vec[self.i]):
            self.i += 1  # Move to next row.
            self.j = 0   # Reset column index.


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(vec)
# param_1 = obj.next()
# param_2 = obj.hasNext()
