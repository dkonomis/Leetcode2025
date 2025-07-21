class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        """
        Problem: 0137 - Single Number II
        
        Find the single number in array where every other element appears three times.
        
        Approach:
        1. Use two variables to simulate a digital circuit.
        2. seen_once tracks bits seen exactly once.
        3. seen_twice tracks bits seen exactly twice.
        4. When a bit is seen three times, both variables reset to 0.
        
        Time complexity: O(n) where n is length of nums.
        Space complexity: O(1) using only constant extra space.
        """
        seen_once = seen_twice = 0
        
        for num in nums:
            # First appearance: add num to seen_once.
            # Second appearance: remove from seen_once, add to seen_twice.
            # Third appearance: remove from seen_twice.
            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)
        
        return seen_once
