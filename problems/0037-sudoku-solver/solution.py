from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        0037. Sudoku Solver

        Problem:
        Fill in a partially completed 9x9 Sudoku board so that every row, column,
        and 3x3 box contains digits 1–9 exactly once. The input board is guaranteed
        to have a unique solution.

        Approach:
        Use backtracking with pruning:
        - Precompute valid digits for each row/col/box.
        - For each empty cell, compute valid candidates by set subtraction.
        - Fill cells with fewest options first to reduce branching (MRV heuristic).

        Time complexity: O(9^n), where n is the number of empty cells.
        Each cell has at most 9 possible digits, so the naive upper bound is 9^n.
        In practice, the MRV heuristic and pruning reduce this dramatically.

        Space complexity: O(1).
        The board and helper sets are fixed in size (9×9), and recursion depth is ≤ n.
        """
        digits = set(str(i) for i in range(1, 10))  # All valid digits.

        rows = [set() for _ in range(9)]  # Digits in each row.
        cols = [set() for _ in range(9)]  # Digits in each column.
        boxes = [set() for _ in range(9)]  # Digits in each 3×3 box.
        empty = []  # List of empty cell positions.

        def box_id(row: int, col: int) -> int:
            # Map a (row, col) to its 3x3 box index.
            return (row // 3) * 3 + (col // 3)

        # Preprocess the board: fill tracking sets and record empty cells.
        for row in range(9):
            for col in range(9):
                val = board[row][col]
                if val == '.':
                    empty.append((row, col))
                else:
                    rows[row].add(val)
                    cols[col].add(val)
                    boxes[box_id(row, col)].add(val)

        # Sort empty cells using the Minimum Remaining Value (MRV) heuristic.
        # Try cells with the fewest valid digit options first to reduce backtracking.
        empty.sort(
            key=lambda pos: len(digits - rows[pos[0]] - cols[pos[1]] - boxes[box_id(pos[0], pos[1])])
        )

        def backtrack(index: int) -> bool:
            # Recursive backtracking over empty cells.
            if index == len(empty):
                return True  # Board is fully solved.

            row, col = empty[index]
            b = box_id(row, col)

            # Determine valid candidates using set subtraction.
            candidates = digits - rows[row] - cols[col] - boxes[b]

            for ch in candidates:
                # Try placing the candidate.
                board[row][col] = ch
                rows[row].add(ch)
                cols[col].add(ch)
                boxes[b].add(ch)

                if backtrack(index + 1):
                    return True  # Success path.

                # Undo and backtrack.
                board[row][col] = '.'
                rows[row].remove(ch)
                cols[col].remove(ch)
                boxes[b].remove(ch)

            return False  # No valid digit worked for this cell.

        backtrack(0)

