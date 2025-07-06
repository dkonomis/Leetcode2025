from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        """
        0035. Search Insert Position

        Problem:
        Given a sorted array of distinct integers and a target, return the index if found.
        If not, return the index where it would be inserted to maintain the sorted order.
        Must run in O(log n) time.

        Approach:
        Use binary search to find the first index where nums[i] >= target.

        Time complexity: O(log n)
        Space complexity: O(1)
        """
        left, right = 0, len(nums) - 1  # Binary search boundaries.

        while left <= right:
            mid = (left + right) // 2  # Midpoint index.

            if nums[mid] == target:
                return mid  # Exact match found.
            elif nums[mid] < target:
                left = mid + 1  # Target is in the right half.
            else:
                right = mid - 1  # Target is in the left half.

        return left  # Left is the insert position.

