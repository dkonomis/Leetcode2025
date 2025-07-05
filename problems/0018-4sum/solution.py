from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        """
        Problem 0018 – 4Sum.

        Given an integer array nums and an integer target, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
        such that: 0 <= a, b, c, d < n, and a, b, c, d are distinct, and nums[a] + nums[b] + nums[c] + nums[d] == target.

        Return the answer in any order.

        This solution generalizes to kSum via recursion.

        Time Complexity  : O(n^{k−1}), where k = 4 here, so worst case is O(n^3).
                           At each level, we fix one number and recurse on the remaining.
        Space Complexity : O(n) recursion stack depth in worst case.
        """

        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []

            # Base case: empty array cannot contribute to any sum.
            if not nums:
                return res

            # Optimization: early termination if target cannot be reached.
            average_value = target // k

            # If the smallest number is too large, or the largest is too small, we can exit early.
            if average_value < nums[0] or nums[-1] < average_value:
                return res

            # Base case: 2Sum problem with two pointers.
            if k == 2:
                return twoSum(nums, target)

            # Recursive case: reduce kSum to (k-1)Sum by choosing one number.
            for i in range(len(nums)):
                # Skip duplicates to ensure uniqueness.
                if i == 0 or nums[i] != nums[i - 1]:
                    # Fix nums[i] and recursively find (k-1)Sum in the suffix.
                    for subset in kSum(nums[i + 1:], target - nums[i], k - 1):
                        res.append([nums[i]] + subset)

            return res

        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            lo, hi = 0, len(nums) - 1

            while lo < hi:
                curr_sum = nums[lo] + nums[hi]

                # Move left pointer to avoid duplicates or if sum is too small.
                if curr_sum < target or (lo > 0 and nums[lo] == nums[lo - 1]):
                    lo += 1

                # Move right pointer to avoid duplicates or if sum is too large.
                elif curr_sum > target or (hi < len(nums) - 1 and nums[hi] == nums[hi + 1]):
                    hi -= 1

                else:
                    # Found a valid pair.
                    res.append([nums[lo], nums[hi]])
                    lo += 1
                    hi -= 1

            return res

        nums.sort()  # Sort to facilitate two-pointer search and duplicate skipping.
        return kSum(nums, target, 4)

