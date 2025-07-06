from typing import List

class Solution:
    """
    0027. Remove Element

    Problem:
    Given an integer array nums and an integer val, remove all occurrences of val in-place.
    Return the number of elements that are not equal to val.
    The order of elements may change, and elements beyond the returned length do not matter.

    Approach:
    Use a write pointer to track the position of the next valid element.
    Iterate through the array with a read pointer.
    If nums[read] is not equal to val, write it at nums[write], then increment write.
    At the end, the first `write` elements will contain all values not equal to val.

    Time Complexity: O(n), where n is the length of the array.
    Space Complexity: O(1), in-place operation.
    """

    def removeElement(self, nums: List[int], val: int) -> int:
        write = 0  # Position to write the next non-val element.

        for read in range(len(nums)):
            if nums[read] != val:
                nums[write] = nums[read]  # Overwrite val element.
                write += 1  # Move write pointer.

        return write  # Number of elements not equal to val.

