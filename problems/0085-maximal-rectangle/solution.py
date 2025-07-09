class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        """
        Problem: 0085 - Maximal Rectangle

        Given a binary matrix filled with '0's and '1's, return the area of the largest rectangle containing only '1's.

        Approach:
        - For each row, treat it as the base of a histogram.
        - Maintain a running list of column heights: heights[j] is the number of consecutive 1s ending at row i in column j.
        - For each updated histogram row, apply the Largest Rectangle in Histogram algorithm (from Problem 0084).
        - Use a monotonic increasing stack to compute max area efficiently.

        Time complexity: O(m × n), where m = number of rows, n = number of columns.
        Space complexity: O(n), for the histogram and stack.
        """
        if not matrix or not matrix[0]:
            return 0

        n = len(matrix[0])
        heights = [0] * n  # Initialize histogram heights for all columns.
        max_area = 0

        for row in matrix:
            # Update histogram heights based on current row.
            for j in range(n):
                if row[j] == '1':
                    heights[j] += 1  # Extend the height by 1.
                else:
                    heights[j] = 0  # Reset height to 0 if we hit a '0'.

            # Compute max rectangle in the updated histogram.
            max_area = max(max_area, self.largestRectangleArea(heights))

        return max_area

    def largestRectangleArea(self, heights: List[int]) -> int:
        # Standard monotonic stack approach to 0084 - Largest Rectangle in Histogram.

        stack = []
        max_area = 0
        heights.append(0)  # Sentinel value to flush the stack.

        for i, h in enumerate(heights):
            # Maintain increasing stack.
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]

                # Compute the width of the rectangle.
                if stack:
                    width = i - stack[-1] - 1
                else:
                    width = i

                # Update maximum area.
                max_area = max(max_area, height * width)

            # Push the current index to the stack.
            stack.append(i)

        heights.pop()  # Restore the original list.
        return max_area

