class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        """
        0162 - Find Peak Element
        
        Given an array, find any peak element (element greater than its neighbors).
        Must solve in O(log n) time complexity.
        
        Approach:
        - Use binary search to efficiently find a peak
        - At each mid point, compare with neighbor to decide search direction
        - If nums[mid] < nums[mid + 1], peak must be on the right side
        - If nums[mid] > nums[mid + 1], peak could be mid or on the left side
        - Continue until left == right, which will be a peak
        
        Time complexity: O(log n).
        Space complexity: O(1).
        """
        left, right = 0, len(nums) - 1
        
        # Binary search to find any peak element.
        while left < right:
            mid = (left + right) // 2
            
            # Compare mid with its right neighbor.
            if nums[mid] < nums[mid + 1]:
                # Peak must be on the right side (including mid + 1).
                left = mid + 1
            else:
                # Peak is either mid or on the left side.
                right = mid
        
        # When left == right, we found a peak.
        return left
