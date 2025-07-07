from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        """
        0041. First Missing Positive

        Problem:
        Given an unsorted integer array nums, return the smallest missing positive integer.
        Must run in O(n) time using constant extra space.

        Approach:
        Use index marking (cyclic sort idea):
        - For each number x in [1, n], place it at index x - 1 if possible.
        - Iterate again to find the first index i where nums[i] != i + 1.
        - That i + 1 is the smallest missing positive.

        Time complexity: O(n), where n = len(nums).
        Each number is moved at most once.

        Space complexity: O(1). In-place rearrangement, no extra space used.
        """

        n = len(nums)

        for i in range(n):
            # Place nums[i] in its correct position if it's in the range [1, n].
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # Swap nums[i] with the value at its target index nums[i] - 1.
                target_idx = nums[i] - 1
                nums[i], nums[target_idx] = nums[target_idx], nums[i]

        # After rearrangement, the first place where nums[i] != i + 1 is the answer.
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        # If all values are placed correctly, the missing one is n + 1.
        return n + 1

