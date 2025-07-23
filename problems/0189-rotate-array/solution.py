class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Problem: 0189 - Rotate Array
        
        Rotate array to the right by k steps in-place.
        
        Approach:
        - Use the reversal algorithm for O(1) space complexity
        - First reverse the entire array
        - Then reverse the first k elements
        - Finally reverse the remaining elements
        - Handle k > len(nums) by using modulo
        
        Time complexity: O(n) where n is the length of the array.
        Space complexity: O(1) as we modify in-place.
        """
        n = len(nums)
        # Normalize k to handle cases where k > n.
        k = k % n
        
        # If k is 0, no rotation needed.
        if k == 0:
            return
        
        def reverse(left, right):
            # Helper function to reverse a portion of the array.
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        
        # Step 1: Reverse the entire array.
        reverse(0, n - 1)
        
        # Step 2: Reverse the first k elements.
        reverse(0, k - 1)
        
        # Step 3: Reverse the remaining elements.
        reverse(k, n - 1)
