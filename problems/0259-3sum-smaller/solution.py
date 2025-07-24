class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        """
        Problem: 0259 - 3Sum Smaller
        
        Sort array then use three pointers. For each fixed element i,
        use two pointers (left, right) to find pairs where sum < target.
        When nums[i] + nums[left] + nums[right] < target, all elements
        between left and right form valid triplets, so add (right - left).
        
        Time complexity: O(n²) where n is the length of nums.
        Space complexity: O(1) excluding the sort space.
        """
        # Sort array for two-pointer approach.
        nums.sort()
        n = len(nums)
        res = 0
        
        # Fix first element.
        for i in range(n - 2):
            left = i + 1
            right = n - 1
            
            # Two-pointer search for valid pairs.
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                
                if total < target:
                    # All elements between left and right form valid triplets.
                    res += right - left
                    left += 1
                else:
                    # Sum too large, decrease right pointer.
                    right -= 1
        
        return res
