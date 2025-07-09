class Solution {
public:
    /*
    Problem: 0073 - Set Matrix Zeroes

    Given an m x n integer matrix, modify it in-place such that
    if an element is 0, its entire row and column are set to 0.

    Approach:
    - Use the first row and first column as markers to track which rows and columns should be zeroed.
    - Use two flags to remember if the first row or first column originally contained any zero.
    - First pass:
        - Traverse the matrix and mark the rows and columns by setting matrix[i][0] and matrix[0][j] to 0.
    - Second pass:
        - Traverse the matrix again (excluding the first row and column), and set matrix[i][j] to 0
          if either matrix[i][0] or matrix[0][j] is 0.
    - Finally, zero out the first row and/or first column if necessary.

    Time Complexity: O(m * n), where m and n are the dimensions of the matrix.
    Space Complexity: O(1), using the matrix itself for markers.
    */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool first_row_zero = false;
        bool first_col_zero = false;

        // Check if the first row contains any zeros.
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                first_row_zero = true;
                break;
            }
        }

        // Check if the first column contains any zeros.
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }

        // Use the first row and first column as markers.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // Mark the i-th row.
                    matrix[0][j] = 0;  // Mark the j-th column.
                }
            }
        }

        // Zero out cells based on the markers.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;  // Set cell to zero if its row or column is marked.
                }
            }
        }

        // Zero out the first row if needed.
        if (first_row_zero) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;  // Set the entire first row to zero.
            }
        }

        // Zero out the first column if needed.
        if (first_col_zero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;  // Set the entire first column to zero.
            }
        }
    }
};

