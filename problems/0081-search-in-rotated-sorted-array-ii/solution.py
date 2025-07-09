class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        """
        Problem: 0081 - Search in Rotated Sorted Array II

        Given a rotated sorted array that may contain duplicates, determine if a target exists.

        Approach:
        - Use a modified binary search.
        - If nums[left] == nums[mid], we cannot determine which half is sorted, so skip left++.
        - Otherwise, determine if left-to-mid or mid-to-right is sorted and apply standard binary search logic.

        Time complexity: O(log n) on average, but O(n) in the worst case due to duplicates.
        Space complexity: O(1).
        """
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return True

            # If duplicates at the boundary, shrink search space.
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            elif nums[left] <= nums[mid]:
                # Left to mid is sorted.
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                # Mid to right is sorted.
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1

        return False

