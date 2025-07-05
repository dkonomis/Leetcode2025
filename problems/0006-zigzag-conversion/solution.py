class Solution:
    def convert(self, s: str, numRows: int) -> str:
        """
        Problem: 0006 - Zigzag Conversion.

        Given a string s and a number of rows, return the string written in a zigzag pattern
        and read line by line.

        Time Complexity: O(n), where n is the length of the string.
        Space Complexity: O(n), for storing the result rows.
        """

        # Edge case: if only one row, return the string as is.
        if numRows == 1 or numRows >= len(s):
            return s

        # Create a list of strings to hold each row.
        rows = [''] * numRows
        curr_row = 0
        going_down = False

        # Iterate through each character in the string.
        for char in s:
            rows[curr_row] += char

            # Reverse direction if we're at the top or bottom row.
            if curr_row == 0 or curr_row == numRows - 1:
                going_down = not going_down

            # Move up or down accordingly.
            curr_row += 1 if going_down else -1

        # Concatenate all rows to form the final string.
        return ''.join(rows)
