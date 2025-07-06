from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        0031. Next Permutation

        Problem:
        Rearrange the list nums into its next lexicographical permutation. 
        If no such permutation exists, rearrange into the lowest possible order.

        Approach:
        1. Traverse from right to left to find the first decreasing element (pivot).
        2. If no pivot is found, reverse the entire list.
        3. Otherwise, find the smallest element greater than pivot from the right.
        4. Swap them, then reverse the suffix.

        Time complexity: O(n)
        Space complexity: O(1)
        """
        n = len(nums)

        # Step 1: Find the first index from the right where nums[i] < nums[i+1].
        pivot = -1
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                pivot = i
                break

        if pivot == -1:
            # The entire array is in descending order. Reverse it to smallest.
            nums.reverse()
            return

        # Step 2: Find the smallest element greater than nums[pivot] to the right.
        for j in range(n - 1, pivot, -1):
            if nums[j] > nums[pivot]:
                # Step 3: Swap nums[pivot] and nums[j].
                nums[pivot], nums[j] = nums[j], nums[pivot]
                break

        # Step 4: Reverse the suffix starting from pivot + 1.
        left, right = pivot + 1, n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

