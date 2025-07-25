class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Problem: 0280 - Wiggle Sort
        
        Reorder array in-place so nums[0] <= nums[1] >= nums[2] <= nums[3]...
        For each position, check if it violates the wiggle property and swap
        if needed. At odd indices, nums[i] should be >= nums[i-1]. At even
        indices, nums[i] should be <= nums[i-1].
        
        Time complexity: O(n).
        Space complexity: O(1).
        """
        # Process each element starting from index 1.
        for i in range(1, len(nums)):
            # At odd index: should be greater than or equal to previous.
            if i % 2 == 1:
                if nums[i] < nums[i - 1]:
                    nums[i], nums[i - 1] = nums[i - 1], nums[i]
            # At even index: should be less than or equal to previous.
            else:
                if nums[i] > nums[i - 1]:
                    nums[i], nums[i - 1] = nums[i - 1], nums[i]
        
        # Modify in-place, no return needed.
        res = None
        return res
