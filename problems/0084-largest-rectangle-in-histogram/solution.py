class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        """
        Problem: 0084 - Largest Rectangle in Histogram

        Given an array of integers representing the heights of bars in a histogram,
        return the area of the largest rectangle that can be formed.

        Approach:
        - Use a monotonic increasing stack to track indices of bars.
        - Append a zero at the end to flush the stack.
        - For each bar, while the current height is less than the height at the top of the stack,
          pop from the stack and calculate the area of rectangle using the popped height.
        - Width is determined by the difference between the current index and the new top of the stack.

        Time complexity: O(n), where n = len(heights)
        Space complexity: O(n)
        """
        stack = []  # Stack to store indices of increasing bar heights.
        max_area = 0
        heights.append(0)  # Sentinel to flush remaining bars from the stack.

        for i, h in enumerate(heights):
            # Maintain an increasing stack.
            while stack and heights[stack[-1]] > h:
                height = heights[stack.pop()]  # Height of the bar being removed.

                # Calculate width:
                if stack:
                    # Stack is not empty after pop, so the rectangle extends
                    # from the element after stack[-1] up to (but not including) i.
                    width = i - stack[-1] - 1
                else:
                    # Stack is empty after pop, so the rectangle extends from index 0 to i.
                    width = i

                # Compute the area using popped height and calculated width.
                max_area = max(max_area, height * width)

            # Push the current index to the stack.
            stack.append(i)

        return max_area

