#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        /*
        51. N-Queens

        Summary:
        Place n queens on an n×n chessboard such that no two queens threaten each other.
        Return all distinct valid board configurations.

        Approach:
        - Use backtracking to build the board row by row.
        - At each row, try placing a queen in any column that is not under attack.
        - Track columns, major diagonals, and minor diagonals that are already occupied.
        - When a full configuration is found, build the string board and add it to the result.

        Time complexity: O(n!), worst-case exponential due to recursive branching.
        Space complexity: O(n), for current path and sets.
        */
        vector<vector<string>> res;       // list of valid solutions.
        vector<int> path;                 // current queen positions by column index.
        unordered_set<int> cols;         // occupied columns.
        unordered_set<int> diag1;        // occupied major diagonals (row - col).
        unordered_set<int> diag2;        // occupied minor diagonals (row + col).

        // Recursive backtracking function.
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                // Build a valid board configuration from path.
                vector<string> board;
                for (int col : path) {
                    string line(n, '.');
                    line[col] = 'Q';
                    board.push_back(line);
                }
                res.push_back(board);
                return;
            }

            // Try placing a queen in each column of the current row.
            for (int col = 0; col < n; ++col) {
                if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                    continue;  // skip if under attack.
                }

                // Place queen.
                path.push_back(col);
                cols.insert(col);
                diag1.insert(row - col);
                diag2.insert(row + col);

                backtrack(row + 1);  // recurse to next row.

                // Backtrack.
                path.pop_back();
                cols.erase(col);
                diag1.erase(row - col);
                diag2.erase(row + col);
            }
        };

        backtrack(0);
        return res;
    }
};

