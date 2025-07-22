class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        """
        0163 - Missing Ranges
        
        Given a sorted array and range [lower, upper], find all missing ranges.
        Return list of [start, end] pairs representing consecutive missing numbers.
        
        Approach:
        - Handle empty array case first
        - Check for missing range before first element
        - Check gaps between consecutive elements
        - Check for missing range after last element
        - Each gap of size > 1 represents a missing range
        
        Time complexity: O(n).
        Space complexity: O(1).
        """
        n = len(nums)
        res = []
        
        # Handle empty array case.
        if n == 0:
            return [[lower, upper]]
        
        # Check for missing range before first element.
        if nums[0] > lower:
            res.append([lower, nums[0] - 1])
        
        # Check gaps between consecutive elements.
        for i in range(1, n):
            if nums[i] - nums[i - 1] > 1:
                # Found a gap, add missing range.
                res.append([nums[i - 1] + 1, nums[i] - 1])
        
        # Check for missing range after last element.
        if nums[-1] < upper:
            res.append([nums[-1] + 1, upper])
        
        return res
