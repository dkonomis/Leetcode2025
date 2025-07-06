from typing import List

class Solution:
    """
    0026. Remove Duplicates from Sorted Array

    Problem:
    Given a sorted integer array nums, remove the duplicates in-place such that each unique element appears only once.
    The relative order of the elements should be preserved.
    You must return the number of unique elements, k, and modify the input array so that the first k elements are the result.
    The rest of the array beyond index k can contain any values.

    Approach:
    Use a two-pointer technique:
        - One pointer (write) tracks where the next unique element should be written.
        - The other pointer (read) scans through the array.
    For each number, if it is different from the previous one, write it to the write pointer and advance both.
    This works in-place because the array is sorted.

    Time Complexity: O(n), where n is the length of the array.
    Space Complexity: O(1), in-place algorithm.
    """

    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0  # Handle empty array edge case.

        write = 1  # Start writing from index 1.
        for read in range(1, len(nums)):
            if nums[read] != nums[read - 1]:
                nums[write] = nums[read]  # Copy unique element forward.
                write += 1  # Move write pointer.

        return write  # Number of unique elements.

