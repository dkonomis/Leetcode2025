class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        """
        Problem 0016 – 3Sum Closest.

        Given an integer array nums and an integer target, find three integers
        in nums such that the sum is closest to target. Return the sum of the three integers.

        It is guaranteed that exactly one solution exists.

        Time Complexity  : O(n^2), where n = len(nums).
        Space Complexity : O(1).
        """

        nums.sort()  # Sort the array for two-pointer traversal.
        closest = float('inf')  # Best sum found so far.

        for i in range(len(nums)):
            # Initialize two pointers.
            left = i + 1
            right = len(nums) - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                # If this sum is closer to target than the previous best, update it.
                if abs(total - target) < abs(closest - target):
                    closest = total

                if total < target:
                    left += 1  # Need a larger sum.
                elif total > target:
                    right -= 1  # Need a smaller sum.
                else:
                    return target  # Exact match found.

        return closest  # Return the closest sum found.

