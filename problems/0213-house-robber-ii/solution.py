class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        Problem: 0213 - House Robber II
        
        Houses are arranged in a circle, so we can't rob both first and last house.
        We solve this by considering two cases: rob houses 0 to n-2, or rob houses 1 to n-1.
        For each case, we use dynamic programming similar to House Robber I.
        
        Time complexity: O(n) where n is the number of houses.
        Space complexity: O(1).
        """
        n = len(nums)
        
        # Edge case: only one house.
        if n == 1:
            return nums[0]
        
        # Edge case: only two houses.
        if n == 2:
            return max(nums[0], nums[1])
        
        # Case 1: Rob houses from 0 to n-2 (exclude last house).
        max1 = self.rob_linear(nums, 0, n - 2)
        
        # Case 2: Rob houses from 1 to n-1 (exclude first house).
        max2 = self.rob_linear(nums, 1, n - 1)
        
        # Return the maximum of both cases.
        return max(max1, max2)
    
    def rob_linear(self, nums: List[int], start: int, end: int) -> int:
        """Helper function to rob houses in a linear arrangement."""
        prev2 = 0  # Maximum money robbed up to i-2.
        prev1 = 0  # Maximum money robbed up to i-1.
        
        # Iterate through houses from start to end.
        for i in range(start, end + 1):
            # Current max is either rob current house + prev2, or skip current and take prev1.
            curr = max(nums[i] + prev2, prev1)
            prev2 = prev1
            prev1 = curr
        
        return prev1
