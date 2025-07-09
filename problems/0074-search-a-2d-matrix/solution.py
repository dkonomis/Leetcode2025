class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
        Problem: 0074 - Search a 2D Matrix

        You are given a 2D matrix with rows sorted in increasing order and
        each row's first element greater than the last of the previous row.
        Determine if a target value exists in the matrix.

        Approach:
        - Use binary search over the virtual flattened matrix (length m * n).
        - Convert the 1D index mid into 2D indices: row = mid // n, col = mid % n.
        - Compare the matrix value at that position to the target.

        Time complexity: O(log(m * n)), where m = rows, n = columns.
        Space complexity: O(1)
        """
        if not matrix or not matrix[0]:
            return False  # Edge case: empty matrix.

        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1

        # Perform binary search on the flattened index space.
        while left <= right:
            mid = (left + right) // 2
            row, col = divmod(mid, n)
            val = matrix[row][col]

            if val == target:
                return True  # Target found.
            elif val < target:
                left = mid + 1  # Search in the right half.
            else:
                right = mid - 1  # Search in the left half.

        return False  # Target not found.

