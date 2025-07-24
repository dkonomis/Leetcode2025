class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        """
        Problem: 0228 - Summary Ranges
        
        Find consecutive ranges in a sorted array.
        Track start of each range and extend while numbers are consecutive.
        Format as "a->b" for ranges or "a" for single numbers.
        
        Time complexity: O(n) where n is the length of nums.
        Space complexity: O(1) excluding the output list.
        """
        if not nums:
            return []
        
        res = []
        start = 0  # Start index of current range.
        
        for i in range(len(nums)):
            # Check if current number breaks the consecutive sequence.
            # This happens at the last element or when next number is not consecutive.
            if i == len(nums) - 1 or nums[i + 1] != nums[i] + 1:
                # Found end of current range.
                if start == i:
                    # Single number range.
                    res.append(str(nums[start]))
                else:
                    # Multi-number range.
                    res.append(f"{nums[start]}->{nums[i]}")
                # Update start for next range.
                start = i + 1
        
        return res
