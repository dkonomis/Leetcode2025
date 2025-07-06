from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        """
        0034. Find First and Last Position of Element in Sorted Array

        Problem:
        Given a sorted array, find the starting and ending position of a given target value.
        If target is not found, return [-1, -1]. Must run in O(log n) time.

        Approach:
        Use a single binary search function with a 'find_first' flag.
        If find_first is True, we search for the leftmost index.
        If find_first is False, we search for the rightmost index.

        Time complexity: O(log n)
        Space complexity: O(1)
        """

        def binary_search(find_first: bool) -> int:
            left, right = 0, len(nums) - 1  # Initialize binary search bounds.
            pos = -1                        # Default if target not found.

            while left <= right:
                mid = (left + right) // 2  # Midpoint index.

                if nums[mid] == target:
                    pos = mid              # Save current index as potential result.
                    if find_first:
                        right = mid - 1    # Narrow to left half.
                    else:
                        left = mid + 1     # Narrow to right half.
                elif nums[mid] < target:
                    left = mid + 1         # Target is in the right half.
                else:
                    right = mid - 1        # Target is in the left half.

            return pos

        return [binary_search(True), binary_search(False)]

