class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Problem: 0075 - Sort Colors

        Given an array nums with 0s, 1s, and 2s representing red, white, and blue,
        sort them in-place so that objects of the same color are adjacent and ordered
        as 0, then 1, then 2.

        Approach:
        - Use the Dutch National Flag algorithm.
        - Maintain three pointers:
            - left: boundary between 0s and 1s.
            - right: boundary between 2s and unknowns.
            - mid: current index to examine.
        - Swap 0s to the front, 2s to the back, and leave 1s in place.

        Time complexity: O(n), where n is the length of nums.
        Space complexity: O(1)
        """
        left, mid, right = 0, 0, len(nums) - 1

        # Process elements until mid passes the right boundary.
        while mid <= right:
            if nums[mid] == 0:
                nums[mid], nums[left] = nums[left], nums[mid]  # Swap to front.
                left += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1  # Leave 1s in place.
            else:
                nums[mid], nums[right] = nums[right], nums[mid]  # Swap to end.
                right -= 1  # Do not increment mid yet to re-check the swapped value.

