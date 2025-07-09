class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Problem: 0073 - Set Matrix Zeroes

        Given an m x n integer matrix, modify it in-place such that
        if an element is 0, its entire row and column are set to 0.

        Approach:
        - Use the first row and first column as markers to track which rows and columns should be zeroed.
        - Use two flags to remember if the first row or first column originally contained any zero.
        - Iterate through the matrix:
            - If matrix[i][j] == 0, mark the i-th row and j-th column by setting matrix[i][0] and matrix[0][j] to 0.
        - Traverse the matrix again (excluding first row and column), and zero out cells based on markers.
        - Finally, zero out the first row and/or column if needed.

        Time complexity: O(m * n), where m and n are the dimensions of the matrix.
        Space complexity: O(1), since we reuse the matrix itself for marking.
        """
        m, n = len(matrix), len(matrix[0])
        first_row_zero = any(matrix[0][j] == 0 for j in range(n))
        first_col_zero = any(matrix[i][0] == 0 for i in range(m))

        # Use the first row and first column as markers.
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0  # Mark row i.
                    matrix[0][j] = 0  # Mark column j.

        # Zero out cells based on markers in the first row and column.
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0  # Set to zero if row or column is marked.

        # Zero out the first row if needed.
        if first_row_zero:
            for j in range(n):
                matrix[0][j] = 0  # Set entire first row to zero.

        # Zero out the first column if needed.
        if first_col_zero:
            for i in range(m):
                matrix[i][0] = 0  # Set entire first column to zero.

