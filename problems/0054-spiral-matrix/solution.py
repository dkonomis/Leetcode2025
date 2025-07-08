class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        """
        54. Spiral Matrix

        Summary:
        Traverse a 2D matrix in spiral order and return the resulting list.

        Approach:
        - Use four boundaries: top, bottom, left, right.
        - Repeatedly traverse the edges of the current "layer":
            - From left to right across the top.
            - From top to bottom along the right.
            - From right to left across the bottom (if still valid).
            - From bottom to top along the left (if still valid).
        - After each full pass, shrink the boundaries inward.

        Time complexity: O(m * n), where m and n are the dimensions of the matrix.
        Space complexity: O(1) extra space (not counting the output list).
        """
        res = []  # final spiral order list.
        if not matrix:
            return res

        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1

        while top <= bottom and left <= right:
            # Traverse from left to right across the top row.
            for col in range(left, right + 1):
                res.append(matrix[top][col])
            top += 1  # move top boundary down.

            # Traverse from top to bottom down the right column.
            for row in range(top, bottom + 1):
                res.append(matrix[row][right])
            right -= 1  # move right boundary left.

            # Traverse from right to left along the bottom row.
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    res.append(matrix[bottom][col])
                bottom -= 1  # move bottom boundary up.

            # Traverse from bottom to top up the left column.
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    res.append(matrix[row][left])
                left += 1  # move left boundary right.

        return res

