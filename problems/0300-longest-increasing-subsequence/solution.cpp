class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /**
         * Problem: 0300 - Longest Increasing Subsequence
         * 
         * Find the length of the longest strictly increasing subsequence.
         * 
         * Approach: Dynamic Programming. dp[i] represents the length of the
         * longest increasing subsequence ending at index i. For each position,
         * check all previous elements - if smaller, we can extend that subsequence.
         * 
         * Time complexity: O(n^2), where n is the length of nums.
         * Space complexity: O(n) for the dp array.
         */
        
        int n = nums.size();
        // dp[i] = length of LIS ending at index i.
        vector<int> dp(n, 1);
        
        // For each position i.
        for (int i = 1; i < n; i++) {
            // Check all previous positions j.
            for (int j = 0; j < i; j++) {
                // If we can extend the subsequence ending at j.
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // The answer is the maximum length found.
        return *max_element(dp.begin(), dp.end());
    }
};
