class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        """
        53. Maximum Subarray

        Summary:
        Find the contiguous subarray with the largest sum using Kadane's Algorithm.

        Approach:
        - Initialize two variables:
            - curr_sum: max subarray sum ending at current position.
            - max_sum: global maximum subarray sum found so far.
        - For each element:
            - Either extend the previous subarray or start a new one at current element.
            - Update max_sum if curr_sum exceeds it.

        Time complexity: O(n), where n = len(nums)
        Space complexity: O(1)
        """
        curr_sum = nums[0]  # maximum subarray ending at first index.
        max_sum = nums[0]   # global maximum subarray sum.

        for num in nums[1:]:
            curr_sum = max(num, curr_sum + num)  # extend or restart.
            max_sum = max(max_sum, curr_sum)     # update global max if needed.

        return max_sum

