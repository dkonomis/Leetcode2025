class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        """
        59. Spiral Matrix II

        Summary:
        Generate an n × n matrix filled with numbers from 1 to n^2 in spiral order.

        Approach:
        - Use four boundaries (top, bottom, left, right) to control traversal.
        - At each step, fill values while spiraling inward:
            - left to right (top row)
            - top to bottom (right column)
            - right to left (bottom row)
            - bottom to top (left column)
        - After each layer, move the boundaries inward.

        Time complexity: O(n^2)
        Space complexity: O(n^2), for the output matrix
        """
        matrix = [[0] * n for _ in range(n)]  # initialize n x n matrix with zeros
        num = 1  # start filling from 1
        top, bottom = 0, n - 1
        left, right = 0, n - 1

        while top <= bottom and left <= right:
            # Fill top row left to right
            for col in range(left, right + 1):
                matrix[top][col] = num
                num += 1
            top += 1

            # Fill right column top to bottom
            for row in range(top, bottom + 1):
                matrix[row][right] = num
                num += 1
            right -= 1

            # Fill bottom row right to left
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    matrix[bottom][col] = num
                    num += 1
                bottom -= 1

            # Fill left column bottom to top
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    matrix[row][left] = num
                    num += 1
                left += 1

        return matrix

