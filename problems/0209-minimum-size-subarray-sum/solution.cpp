class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
         * Problem: 0209 - Minimum Size Subarray Sum
         * Given array of positive integers and target, find minimal length of subarray
         * whose sum is greater than or equal to target.
         * 
         * Approach: Use sliding window with two pointers. Expand right to increase sum,
         * shrink left when sum >= target to minimize window size.
         * 
         * Time complexity: O(n) where n is length of nums.
         * Space complexity: O(1).
         */
        
        int left = 0;
        int current_sum = 0;
        int min_length = INT_MAX;
        
        // Expand window with right pointer.
        for (int right = 0; right < nums.size(); right++) {
            // Add current element to window sum.
            current_sum += nums[right];
            
            // Shrink window from left while sum >= target.
            while (current_sum >= target) {
                // Update minimum length found so far.
                min_length = min(min_length, right - left + 1);
                // Remove leftmost element and shrink window.
                current_sum -= nums[left];
                left++;
            }
        }
        
        // Return 0 if no valid subarray found, otherwise return min length.
        return min_length == INT_MAX ? 0 : min_length;
    }
};
