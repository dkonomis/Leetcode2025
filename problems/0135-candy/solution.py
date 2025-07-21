class Solution:
    def candy(self, ratings: List[int]) -> int:
        """
        Problem: 0135 - Candy
        
        Find minimum candies needed with rating constraints.
        
        Approach:
        1. Initialize all children with 1 candy (minimum requirement).
        2. Left-to-right pass: ensure higher rating gets more than left neighbor.
        3. Right-to-left pass: ensure higher rating gets more than right neighbor.
        4. Two passes handle both neighbor constraints independently.
        
        Time complexity: O(n) where n is number of children.
        Space complexity: O(n) for the candies array.
        """
        n = len(ratings)
        candies = [1] * n  # Each child gets at least 1 candy.
        
        # Left-to-right pass: handle left neighbor constraints.
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        
        # Right-to-left pass: handle right neighbor constraints.
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                # Take maximum to preserve left neighbor constraints.
                candies[i] = max(candies[i], candies[i + 1] + 1)
        
        return sum(candies)
