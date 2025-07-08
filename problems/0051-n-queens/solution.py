class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        """
        51. N-Queens

        Summary:
        Place n queens on an n×n chessboard such that no two queens threaten each other.
        Return all distinct valid board configurations.

        Approach:
        - Use backtracking to build the solution row by row.
        - At each row, try placing a queen in any column that is not under attack.
        - Track columns, major diagonals, and minor diagonals that are already occupied.
        - When a full configuration is found, convert it to the required string format and add to result.

        Time complexity: O(n!), worst-case exponential due to recursive branching.
        Space complexity: O(n), for the current path and sets.
        """
        def backtrack(row: int):
            # If all n rows are filled, we found a valid solution.
            if row == n:
                board = []
                for col in path:
                    line = ['.'] * n
                    line[col] = 'Q'
                    board.append(''.join(line))
                res.append(board)
                return

            # Try placing a queen in each column of the current row.
            for col in range(n):
                if col in cols or (row - col) in diag1 or (row + col) in diag2:
                    continue  # skip if under attack.

                # Place queen.
                path.append(col)
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)

                backtrack(row + 1)  # recurse to next row.

                # Backtrack.
                path.pop()
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        res = []           # list of valid solutions.
        path = []          # current queen positions by column index.
        cols = set()       # occupied columns.
        diag1 = set()      # occupied major diagonals (row - col).
        diag2 = set()      # occupied minor diagonals (row + col).

        backtrack(0)
        return res

