#include <unordered_set>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        /*
        52. N-Queens II

        Summary:
        Use a recursive lambda with captured state to explore all valid queen placements.
        Return the total number of valid configurations.

        Time complexity: O(n!)
        Space complexity: O(n)
        */
        int res = 0;
        unordered_set<int> cols;    // occupied columns.
        unordered_set<int> diag1;   // occupied major diagonals (row - col).
        unordered_set<int> diag2;   // occupied minor diagonals (row + col).

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                res += 1;  // found a valid configuration.
                return;
            }

            // Try placing a queen in each column of the current row.
            for (int col = 0; col < n; ++col) {
                if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                    continue;  // skip if under attack.
                }

                // Place queen.
                cols.insert(col);
                diag1.insert(row - col);
                diag2.insert(row + col);

                backtrack(row + 1);  // recurse to next row.

                // Backtrack.
                cols.erase(col);
                diag1.erase(row - col);
                diag2.erase(row + col);
            }
        };

        backtrack(0);
        return res;
    }
};


