class Solution:
    def countDigitOne(self, n: int) -> int:
        """
        Problem: 0233 - Number of Digit One
        
        Count occurrences of digit 1 in all numbers from 0 to n.
        Process each digit position and count 1s at that position.
        For each position, count depends on digits before, at, and after.
        
        Time complexity: O(log n) where log n is the number of digits.
        Space complexity: O(1).
        """
        if n <= 0:
            return 0
        
        count = 0
        factor = 1  # Current digit position (1, 10, 100, ...).
        
        while factor <= n:
            # Divide number into parts around current digit.
            # Example: n = 3141, factor = 100.
            # higher = 31, cur = 1, lower = 41.
            lower = n % factor
            cur = (n // factor) % 10
            higher = n // (factor * 10)
            
            # Count 1s from complete cycles of higher digits.
            # Each complete cycle contributes factor 1s at this position.
            count += higher * factor
            
            # Count 1s from the current digit.
            if cur > 1:
                # Current digit > 1: add all possible 1s at this position.
                count += factor
            elif cur == 1:
                # Current digit = 1: add partial 1s based on lower digits.
                count += lower + 1
            # If cur = 0, no additional 1s at this position.
            
            # Move to next digit position.
            factor *= 10
        
        return count
