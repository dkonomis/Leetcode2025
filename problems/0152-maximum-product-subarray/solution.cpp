class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /**
         * Problem: 0152 - Maximum Product Subarray
         * 
         * Find contiguous subarray with largest product.
         * 
         * Approach:
         * Track both max and min products ending at each position.
         * Min can become max when multiplied by negative number.
         * Handle zeros by resetting to current number.
         * 
         * Time complexity: O(n).
         * Space complexity: O(1).
         */
        
        if (nums.empty()) {
            return 0;
        }
        
        // Initialize with first element.
        int max_prod = nums[0];
        int min_prod = nums[0];
        int res = nums[0];
        
        // Process remaining elements.
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            
            // When we multiply by negative, max and min can swap.
            // So we need to consider all possibilities.
            // Important: Store max in temp variable to use old max_prod value
            // when calculating min_prod (not the updated one).
            int temp_max = max({curr, max_prod * curr, min_prod * curr});
            min_prod = min({curr, max_prod * curr, min_prod * curr});
            max_prod = temp_max;
            
            // Update global maximum.
            res = max(res, max_prod);
        }
        
        return res;
    }
};
