class Solution:
    def addDigits(self, num: int) -> int:
        """
        Problem: 0258 - Add Digits
        
        Use digital root formula: (num - 1) % 9 + 1.
        This works because the digital root follows a pattern:
        1->1, 2->2, ..., 9->9, 10->1, 11->2, ..., 18->9, 19->1, ...
        Special case: 0 returns 0.
        
        Time complexity: O(1) using mathematical formula.
        Space complexity: O(1) constant space.
        """
        # Handle special case.
        if num == 0:
            return 0
        
        # Apply digital root formula.
        return (num - 1) % 9 + 1
