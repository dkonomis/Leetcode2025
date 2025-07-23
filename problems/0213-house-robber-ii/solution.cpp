class Solution {
public:
    int rob(vector<int>& nums) {
        /**
         * Problem: 0213 - House Robber II
         * 
         * Houses are arranged in a circle, so we can't rob both first and last house.
         * We solve this by considering two cases: rob houses 0 to n-2, or rob houses 1 to n-1.
         * For each case, we use dynamic programming similar to House Robber I.
         * 
         * Time complexity: O(n) where n is the number of houses.
         * Space complexity: O(1).
         */
        
        int n = nums.size();
        
        // Edge case: only one house.
        if (n == 1) {
            return nums[0];
        }
        
        // Edge case: only two houses.
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        // Case 1: Rob houses from 0 to n-2 (exclude last house).
        int max1 = robLinear(nums, 0, n - 2);
        
        // Case 2: Rob houses from 1 to n-1 (exclude first house).
        int max2 = robLinear(nums, 1, n - 1);
        
        // Return the maximum of both cases.
        return max(max1, max2);
    }
    
private:
    int robLinear(vector<int>& nums, int start, int end) {
        // Helper function to rob houses in a linear arrangement.
        int prev2 = 0;  // Maximum money robbed up to i-2.
        int prev1 = 0;  // Maximum money robbed up to i-1.
        
        // Iterate through houses from start to end.
        for (int i = start; i <= end; i++) {
            // Current max is either rob current house + prev2, or skip current and take prev1.
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
