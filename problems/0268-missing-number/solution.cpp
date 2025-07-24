class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /**
         * Problem: 0268 - Missing Number
         * 
         * Find the missing number from range [0, n] where n = len(nums).
         * 
         * Approach: Use mathematical formula for sum of first n natural numbers: n*(n+1)/2.
         * Calculate expected sum minus actual sum to find the missing number.
         * 
         * Time complexity: O(n) where n is the length of the array.
         * Space complexity: O(1) using only constant extra space.
         */
        
        int n = nums.size();
        
        // Expected sum of numbers from 0 to n.
        int expected_sum = n * (n + 1) / 2;
        
        // Actual sum of array elements.
        int actual_sum = 0;
        for (int num : nums) {
            actual_sum += num;
        }
        
        // Missing number is the difference.
        return expected_sum - actual_sum;
    }
};
