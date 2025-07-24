class Solution:
    def isUgly(self, n: int) -> bool:
        """
        Problem: 0263 - Ugly Number
        
        Check if n only has prime factors 2, 3, and 5.
        Keep dividing by 2, 3, and 5 while divisible.
        If we reach 1, all prime factors were 2, 3, or 5.
        
        Time complexity: O(log n) as we divide n repeatedly.
        Space complexity: O(1) using only constant space.
        """
        # Negative numbers and 0 are not ugly.
        if n <= 0:
            return False
        
        # Keep dividing by 2, 3, and 5.
        for factor in [2, 3, 5]:
            while n % factor == 0:
                n //= factor
        
        # If n is reduced to 1, it's ugly.
        return n == 1
