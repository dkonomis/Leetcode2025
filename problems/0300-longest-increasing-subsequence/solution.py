class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        """
        Problem: 0300 - Longest Increasing Subsequence
        
        Find the length of the longest strictly increasing subsequence.
        
        Approach: Dynamic Programming. dp[i] represents the length of the
        longest increasing subsequence ending at index i. For each position,
        check all previous elements - if smaller, we can extend that subsequence.
        
        Time complexity: O(n^2), where n is the length of nums.
        Space complexity: O(n) for the dp array.
        """
        n = len(nums)
        # dp[i] = length of LIS ending at index i.
        dp = [1] * n
        
        # For each position i.
        for i in range(1, n):
            # Check all previous positions j.
            for j in range(i):
                # If we can extend the subsequence ending at j.
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        # The answer is the maximum length found.
        return max(dp)
