class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        Problem: 0154 - Find Minimum in Rotated Sorted Array II
        
        Find minimum element in a rotated sorted array with duplicates.
        
        Approach:
        Modified binary search. When mid equals right, we can't determine
        which half has the minimum, so decrement right by 1.
        This handles duplicates but degrades to O(n) worst case.
        
        Time complexity: O(log n) average, O(n) worst case.
        Space complexity: O(1).
        """
        left = 0
        right = len(nums) - 1
        
        while left < right:
            mid = left + (right - left) // 2
            
            if nums[mid] > nums[right]:
                # Minimum is definitely in right half.
                left = mid + 1
            elif nums[mid] < nums[right]:
                # Minimum is in left half (including mid).
                right = mid
            else:
                # nums[mid] == nums[right] - can't determine which half.
                # Safely eliminate right element and try again.
                # We know nums[right] can't be the unique minimum
                # since nums[mid] has the same value.
                right -= 1
        
        return nums[left]
