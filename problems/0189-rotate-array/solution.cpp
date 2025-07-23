class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /**
         * Problem: 0189 - Rotate Array
         * 
         * Rotate array to the right by k steps in-place.
         * 
         * Approach:
         * - Use the reversal algorithm for O(1) space complexity
         * - First reverse the entire array
         * - Then reverse the first k elements
         * - Finally reverse the remaining elements
         * - Handle k > len(nums) by using modulo
         * 
         * Time complexity: O(n) where n is the length of the array.
         * Space complexity: O(1) as we modify in-place.
         */
        
        int n = nums.size();
        // Normalize k to handle cases where k > n.
        k = k % n;
        
        // If k is 0, no rotation needed.
        if (k == 0) {
            return;
        }
        
        // Step 1: Reverse the entire array.
        reverse(nums, 0, n - 1);
        
        // Step 2: Reverse the first k elements.
        reverse(nums, 0, k - 1);
        
        // Step 3: Reverse the remaining elements.
        reverse(nums, k, n - 1);
    }
    
private:
    void reverse(vector<int>& nums, int left, int right) {
        // Helper function to reverse a portion of the array.
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
