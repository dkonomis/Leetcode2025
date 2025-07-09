class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        Problem: 0080 - Remove Duplicates from Sorted Array II

        Given a sorted array, remove duplicates in-place such that each unique element
        appears at most twice. Return the length of the modified array.

        Approach:
        - Use a two-pointer technique.
        - Keep a write pointer that only advances when an element is allowed.
        - Allow up to two occurrences of each unique value.
        - Compare with the value two positions before the current write index.

        Time complexity: O(n), where n is the length of the input array.
        Space complexity: O(1), in-place modification.
        """
        if len(nums) <= 2:
            return len(nums)

        write = 2  # Start writing from index 2.

        # Iterate through the array starting from index 2.
        for read in range(2, len(nums)):
            # Only write if current value is not the same as the value two positions back.
            if nums[read] != nums[write - 2]:
                nums[write] = nums[read]  # Overwrite the write index with the read value.
                write += 1  # Move the write pointer forward.

        return write

