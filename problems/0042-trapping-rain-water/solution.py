from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        """
        0042. Trapping Rain Water

        Problem:
        Given n non-negative integers representing an elevation map where the width of each bar is 1,
        compute how much water it can trap after raining.

        Approach:
        Use two-pointer technique:
        - Maintain left and right pointers, moving inward.
        - Keep track of left_max and right_max.
        - At each step, trap water based on the shorter boundary.
        - This avoids precomputing arrays and achieves O(1) space.

        Time complexity: O(n), where n is len(height).
        Each index is visited at most once.

        Space complexity: O(1), using only constant extra variables.
        """

        n = len(height)
        if n == 0:
            return 0

        # Initialize two pointers at both ends of the array.
        left, right = 0, n - 1

        # Track the max height seen so far from both ends.
        left_max, right_max = 0, 0

        # Accumulate total trapped water.
        res = 0

        # Continue until the two pointers meet.
        while left < right:
            if height[left] < height[right]:
                # We're on the lower side — water is bounded by left_max.
                if height[left] >= left_max:
                    # Update left_max if current bar is taller.
                    left_max = height[left]
                else:
                    # Water trapped on this bar = left_max - current height.
                    res += left_max - height[left]
                # Move left pointer inward.
                left += 1
            else:
                # Now we're on the right side — water is bounded by right_max.
                if height[right] >= right_max:
                    # Update right_max if current bar is taller.
                    right_max = height[right]
                else:
                    # Water trapped on this bar = right_max - current height.
                    res += right_max - height[right]
                # Move right pointer inward.
                right -= 1

        return res

