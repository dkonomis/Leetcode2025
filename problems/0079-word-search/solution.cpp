class Solution {
public:
    /*
    Problem: 0079 - Word Search

    Given a 2D grid of characters and a word, determine if the word exists in the grid
    by tracing sequentially adjacent (horizontally or vertically) characters. Each cell
    may be used only once.

    Approach:
    - Try starting a DFS from each cell.
    - At each step, check if the current character matches the word.
    - Mark visited cells temporarily to avoid reuse.
    - Backtrack after each path.

    Time Complexity: O(m × n × 4^L), where m×n is the grid size and L is the word length.
    Space Complexity: O(L) for the recursion call stack.
    */
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Backtracking helper to explore the board.
        function<bool(int, int, int)> dfs = [&](int row, int col, int idx) {
            // If we've matched all characters, return true.
            if (idx == word.size()) {
                return true;
            }

            // Out of bounds or already visited or mismatch.
            if (row < 0 || row >= rows ||
                col < 0 || col >= cols ||
                board[row][col] != word[idx]) {
                return false;
            }

            // Mark this cell as visited by temporarily altering the value.
            char temp = board[row][col];
            board[row][col] = '#';

            // Explore all 4 directions.
            bool found = dfs(row + 1, col, idx + 1) ||
                         dfs(row - 1, col, idx + 1) ||
                         dfs(row, col + 1, idx + 1) ||
                         dfs(row, col - 1, idx + 1);

            // Restore the original value (backtrack).
            board[row][col] = temp;
            return found;
        };

        // Try to start the search from every cell.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

