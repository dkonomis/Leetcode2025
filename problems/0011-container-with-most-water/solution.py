from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Two-pointer approach.
        # Initialize the left and right pointers at the beginning and end of the array.
        left = 0
        right = len(height) - 1

        # Variable to store the maximum area found.
        max_area = 0

        # Move the pointers toward each other.
        while left < right:
            # Calculate the current area formed between lines at left and right.
            current_height = min(height[left], height[right])
            width = right - left
            current_area = current_height * width

            # Update the maximum area if the current one is greater.
            if current_area > max_area:
                max_area = current_area

            # Move the pointer pointing to the shorter line inward.
            # This is because the height of the container is limited by the shorter line,
            # and moving it inward might find a taller line that gives a better area.
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        # Return the maximum area found.
        return max_area

