class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        """
        0171 - Excel Sheet Column Number
        
        Convert Excel column title to corresponding column number.
        This is the reverse of problem 168 - converting from letters to number.
        
        Approach:
        - Process string from left to right using base-26 conversion
        - Each character represents a digit in base-26 system
        - A=1, B=2, ..., Z=26 (1-indexed system)
        - For each character: result = result * 26 + char_value
        - Similar to converting "123" to number: result = result * 10 + digit
        
        Time complexity: O(n).
        Space complexity: O(1).
        """
        res = 0
        
        # Process each character from left to right.
        for char in columnTitle:
            # Convert character to its numeric value (A=1, B=2, ..., Z=26).
            char_value = ord(char) - ord('A') + 1
            
            # Base-26 conversion: shift current result and add new digit.
            res = res * 26 + char_value
        
        return res
