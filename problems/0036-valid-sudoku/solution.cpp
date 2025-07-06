#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        0036. Valid Sudoku

        Problem:
        Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated.
        Each row, column, and 3x3 box must contain unique digits 1–9.

        Approach:
        Use hash sets to track digits seen in each row, column, and box.
        For each cell, if the digit is already in the corresponding row/col/box set, return false.
        Otherwise, add it to the sets.

        Time complexity: O(1) since the board is always 9x9.
        Space complexity: O(1) constant extra space for 27 sets.
        */

        vector<unordered_set<char>> rows(9);   // Track digits in each row.
        vector<unordered_set<char>> cols(9);   // Track digits in each column.
        vector<unordered_set<char>> boxes(9);  // Track digits in each 3x3 box.

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];

                if (val == '.') {
                    continue;  // Skip empty cells.
                }

                if (rows[i].count(val)) {
                    return false;  // Duplicate in the same row.
                }
                rows[i].insert(val);

                if (cols[j].count(val)) {
                    return false;  // Duplicate in the same column.
                }
                cols[j].insert(val);

                int box_index = (i / 3) * 3 + (j / 3);  // Compute 3x3 box index.
                if (boxes[box_index].count(val)) {
                    return false;  // Duplicate in the same box.
                }
                boxes[box_index].insert(val);
            }
        }

        return true;  // All checks passed.
    }
};

