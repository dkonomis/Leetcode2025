class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        """
        Problem: 0079 - Word Search

        Given a 2D grid of characters and a word, determine if the word exists in the grid
        by tracing sequentially adjacent (horizontally or vertically) characters. Each cell
        may be used only once.

        Approach:
        - Try starting a DFS from each cell.
        - At each step, check if the current character matches the word.
        - Mark visited cells temporarily to avoid reuse.
        - Backtrack after each path.

        Time complexity: O(m × n × 4^L), where m×n is the grid size and L is the word length.
        Space complexity: O(L) for the recursion call stack.
        """
        rows, cols = len(board), len(board[0])

        def dfs(row, col, idx):
            # If we've matched all characters, return True.
            if idx == len(word):
                return True

            # Out of bounds or already visited or mismatch.
            if (row < 0 or row >= rows or
                col < 0 or col >= cols or
                board[row][col] != word[idx]):
                return False

            # Mark this cell as visited by temporarily altering the value.
            temp = board[row][col]
            board[row][col] = '#'

            # Explore all 4 directions.
            found = (dfs(row + 1, col, idx + 1) or
                     dfs(row - 1, col, idx + 1) or
                     dfs(row, col + 1, idx + 1) or
                     dfs(row, col - 1, idx + 1))

            # Restore the original value (backtrack).
            board[row][col] = temp
            return found

        # Try to start the search from every cell.
        for i in range(rows):
            for j in range(cols):
                if dfs(i, j, 0):
                    return True

        return False

