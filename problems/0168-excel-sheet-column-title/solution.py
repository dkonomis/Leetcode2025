class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        """
        0168 - Excel Sheet Column Title
        
        Convert integer to Excel column title (A, B, C, ..., Z, AA, AB, ...).
        This is like base-26 conversion but with 1-indexed mapping (A=1, not A=0).
        
        Approach:
        - Similar to base conversion but adjust for 1-indexed system
        - Subtract 1 from columnNumber before each operation to handle 1-indexing
        - Use modulo 26 to get current character, divide by 26 to move to next digit
        - Build result from right to left, then reverse (or prepend each character)
        
        Time complexity: O(log₂₆(n)).
        Space complexity: O(log₂₆(n)).
        """
        res = []
        
        # Continue until all digits are processed.
        while columnNumber > 0:
            # Adjust for 1-indexed system: subtract 1 before operations.
            columnNumber -= 1
            
            # Get the rightmost character (A=0, B=1, ..., Z=25 after adjustment).
            char_index = columnNumber % 26
            res.append(chr(ord('A') + char_index))
            
            # Move to next digit position.
            columnNumber //= 26
        
        # Reverse since we built from right to left.
        return ''.join(reversed(res))
