class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
         * Problem: 0238 - Product of Array Except Self
         * 
         * Calculate product of all elements except self without division.
         * Use two passes: left-to-right for prefix products, right-to-left for suffix products.
         * First pass: res[i] = product of all elements to the left of i.
         * Second pass: multiply by product of all elements to the right of i.
         * 
         * Time complexity: O(n) with two passes through the array.
         * Space complexity: O(1) excluding the output array.
         */
        
        int n = nums.size();
        vector<int> res(n, 1);
        
        // First pass: calculate prefix products.
        // res[i] will contain product of all elements before index i.
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        // Second pass: multiply by suffix products.
        // Use a running product from right to left.
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            // Multiply current result by product of elements to the right.
            res[i] *= right_product;
            // Update right product for next iteration.
            right_product *= nums[i];
        }
        
        return res;
    }
};
