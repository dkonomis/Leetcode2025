#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 0037. Sudoku Solver

        // Problem:
        // Fill in a partially completed 9x9 Sudoku board so that every row, column,
        // and 3x3 box contains digits 1–9 exactly once. The input board is guaranteed
        // to have a unique solution.

        // Approach:
        // Use backtracking with pruning.
        // Track digits used in each row, column, and box with fixed-size boolean arrays.
        // Sort empty cells by Minimum Remaining Value (MRV) to reduce the branching factor.

        // Time complexity: O(9^n), where n is the number of empty cells.
        // For each empty cell, we may try up to 9 digits.
        // In practice, pruning and MRV make this much faster.
        // Space complexity: O(1), since all auxiliary data structures are fixed-size.

        const int N = 9;

        // Initialize 9×9 boolean arrays for tracking digit usage in rows, columns, and boxes.
        rows = vector<vector<bool>>(N, vector<bool>(9, false));
        cols = vector<vector<bool>>(N, vector<bool>(9, false));
        boxes = vector<vector<bool>>(N, vector<bool>(9, false));

        empty.clear();  // Clear the list of empty cells.

        // Scan the board and fill the tracking structures.
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < N; ++col) {
                char val = board[row][col];
                if (val == '.') {
                    empty.emplace_back(row, col);  // Track empty cell.
                } else {
                    int d = val - '1';  // Map '1'–'9' → 0–8.
                    rows[row][d] = true;
                    cols[col][d] = true;
                    boxes[box_id(row, col)][d] = true;
                }
            }
        }

        // Apply MRV: sort empty cells by number of available candidates.
        sort(empty.begin(), empty.end(), [&](const pair<int, int>& a,
                                             const pair<int, int>& b) {
            int ar = a.first, ac = a.second;
            int br = b.first, bc = b.second;
            int acount = 0, bcount = 0;

            // Count available digits at position (ar, ac).
            for (int d = 0; d < 9; ++d) {
                if (!rows[ar][d] && !cols[ac][d] && !boxes[box_id(ar, ac)][d]) ++acount;
                if (!rows[br][d] && !cols[bc][d] && !boxes[box_id(br, bc)][d]) ++bcount;
            }

            return acount < bcount;  // Fewer candidates → higher priority.
        });

        // Start the recursive backtracking.
        solve(board, 0);
    }

private:
    // Boolean matrices for digits 1–9 in rows, columns, and boxes.
    vector<vector<bool>> rows, cols, boxes;

    // List of all initially empty cells.
    vector<pair<int, int>> empty;

    int box_id(int row, int col) {
        // Return the index of the 3x3 box containing (row, col).
        return (row / 3) * 3 + col / 3;
    }

    bool solve(vector<vector<char>>& board, int idx) {
        // Recursive backtracking function to fill empty cells.
        if (idx == empty.size()) return true;  // All cells filled.

        int row = empty[idx].first;
        int col = empty[idx].second;
        int box = box_id(row, col);

        // Try placing digits 1–9 at (row, col).
        for (int d = 0; d < 9; ++d) {
            // Skip if digit is already used in row, column, or box.
            if (rows[row][d] || cols[col][d] || boxes[box][d]) continue;

            // Place the digit.
            board[row][col] = static_cast<char>('1' + d);
            rows[row][d] = cols[col][d] = boxes[box][d] = true;

            // Recurse to the next cell.
            if (solve(board, idx + 1)) return true;

            // Backtrack: undo the placement.
            board[row][col] = '.';
            rows[row][d] = cols[col][d] = boxes[box][d] = false;
        }

        // No digit could be placed here.
        return false;
    }
};

