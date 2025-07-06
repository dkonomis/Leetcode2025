from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        """
        0036. Valid Sudoku

        Problem:
        Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated.
        Each row, column, and 3x3 box must contain unique digits 1–9.

        Approach:
        Use hash sets to track digits seen in each row, column, and box.
        For each cell, if the digit is already in the corresponding row/col/box set, return False.
        Otherwise, add it to the sets.

        Time complexity: O(1) since the board is always 9x9.
        Space complexity: O(1) constant extra space for 27 sets.
        """
        rows = [set() for _ in range(9)]      # Track digits in each row.
        cols = [set() for _ in range(9)]      # Track digits in each column.
        boxes = [set() for _ in range(9)]     # Track digits in each 3x3 sub-box.

        for i in range(9):
            for j in range(9):
                val = board[i][j]

                if val == '.':
                    continue  # Skip empty cells.

                if val in rows[i]:
                    return False  # Duplicate in the same row.
                rows[i].add(val)

                if val in cols[j]:
                    return False  # Duplicate in the same column.
                cols[j].add(val)

                box_index = (i // 3) * 3 + (j // 3)  # Compute 3x3 box index.
                if val in boxes[box_index]:
                    return False  # Duplicate in the same box.
                boxes[box_index].add(val)

        return True  # All checks passed.

