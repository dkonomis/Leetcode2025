class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        """
        Problem 0015 – 3Sum.

        Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]]
        such that i ≠ j, i ≠ k, and j ≠ k, and nums[i] + nums[j] + nums[k] == 0.

        The solution set must not contain duplicate triplets.

        Time Complexity  : O(n^2), where n = len(nums).
        Space Complexity : O(n) for sorting, O(k) for result storage.
        """

        res = []  # Final list of triplets.
        nums.sort()  # Sort the array to use two-pointer technique.

        for i in range(len(nums)):
            # Skip duplicates for the first element of the triplet.
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1  # Initialize the second pointer.
            right = len(nums) - 1  # Initialize the third pointer.

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total < 0:
                    left += 1  # Need a larger value.
                elif total > 0:
                    right -= 1  # Need a smaller value.
                else:
                    # Found a valid triplet.
                    res.append([nums[i], nums[left], nums[right]])

                    # Skip duplicates for the second and third elements.
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

        return res

