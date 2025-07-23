class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        Problem: 0198 - House Robber
        
        Given an array of house values, find maximum money that can be robbed
        without robbing adjacent houses (which would trigger security system).
        
        Approach: Dynamic programming. For each house, decide whether to rob it
        or not based on maximum profit. Can't rob adjacent houses.
        
        Time complexity: O(n). 
        Space complexity: O(1).
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        # prev2: max money robbed up to house i-2.
        # prev1: max money robbed up to house i-1.
        prev2 = nums[0]
        prev1 = max(nums[0], nums[1])
        
        # For each house starting from index 2.
        for i in range(2, len(nums)):
            # Current max is either: rob current house + prev2, or skip current house (prev1).
            current = max(prev1, prev2 + nums[i])
            prev2 = prev1  # Update prev2 to previous prev1.
            prev1 = current  # Update prev1 to current max.
        
        return prev1
