class Solution:
    def totalNQueens(self, n: int) -> int:
        """
        52. N-Queens II

        Summary:
        Count the number of distinct ways to place n queens on an n×n chessboard
        such that no two queens attack each other.

        Approach:
        - Use backtracking and return the number of solutions from each recursive call.
        - Sum all valid paths instead of mutating shared state.

        Time complexity: O(n!)
        Space complexity: O(n)
        """
        def backtrack(row: int) -> int:
            if row == n:
                return 1  # found a valid solution.

            total = 0  # local count for this call.

            # Try placing a queen in each column of the current row.
            for col in range(n):
                if col in cols or (row - col) in diag1 or (row + col) in diag2:
                    continue  # skip if under attack.

                # Place queen.
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)

                total += backtrack(row + 1)  # accumulate from recursive calls.

                # Backtrack.
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

            return total

        cols = set()
        diag1 = set()
        diag2 = set()

        return backtrack(0)

