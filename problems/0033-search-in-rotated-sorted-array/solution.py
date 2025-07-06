from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        0033. Search in Rotated Sorted Array

        Problem:
        Given a rotated sorted array with unique integers, return the index of target if it exists, 
        or -1 otherwise. Must run in O(log n) time.

        Approach:
        Use modified binary search:
        - At each step, one half (left or right) must be sorted.
        - Determine which half is sorted and whether the target lies within it.
        - Adjust search bounds accordingly.

        Time complexity: O(log n)
        Space complexity: O(1)
        """
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid  # Found the target.

            if nums[left] <= nums[mid]:
                # Left half is sorted.
                if nums[left] <= target < nums[mid]:
                    right = mid - 1  # Target is in the left half.
                else:
                    left = mid + 1   # Target is in the right half.
            else:
                # Right half is sorted.
                if nums[mid] < target <= nums[right]:
                    left = mid + 1   # Target is in the right half.
                else:
                    right = mid - 1  # Target is in the left half.

        return -1  # Target not found.

