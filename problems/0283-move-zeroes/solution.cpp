class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /**
         * Problem: 0283 - Move Zeroes
         * 
         * Move all zeros to the end of the array while maintaining the
         * relative order of non-zero elements. Must be done in-place.
         * 
         * Approach:
         * - Use two pointers: one to track position for next non-zero element
         * - Iterate through array, placing non-zeros at the front
         * - Fill remaining positions with zeros
         * - This minimizes writes compared to swapping approach
         * 
         * Time complexity: O(n) where n is length of nums.
         * Space complexity: O(1) as we modify in-place.
         */
        
        // Position to place next non-zero element.
        int write_pos = 0;
        
        // First pass: move all non-zero elements to the front.
        for (int num : nums) {
            if (num != 0) {
                nums[write_pos] = num;
                write_pos++;
            }
        }
        
        // Second pass: fill remaining positions with zeros.
        while (write_pos < nums.size()) {
            nums[write_pos] = 0;
            write_pos++;
        }
    }
};
