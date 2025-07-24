class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /**
         * Problem: 0260 - Single Number III
         * 
         * Find two single numbers using XOR and bit manipulation.
         * 1. XOR all numbers to get x ^ y (pairs cancel out).
         * 2. Find a bit where x and y differ (any set bit in x ^ y).
         * 3. Partition numbers by this bit into two groups.
         * 4. XOR each group to get x and y separately.
         * 
         * Time complexity: O(n) with two passes through the array.
         * Space complexity: O(1) using only constant extra space.
         */
        
        // Step 1: XOR all numbers to get x ^ y.
        int xor_all = 0;
        for (int num : nums) {
            xor_all ^= num;
        }
        
        // Step 2: Find rightmost set bit (where x and y differ).
        // x & -x isolates the rightmost set bit.
        // Cast to unsigned to avoid overflow with INT_MIN.
        int diff_bit = xor_all & -(unsigned int)xor_all;
        
        // Step 3 & 4: Partition and XOR each group.
        int x = 0, y = 0;
        for (int num : nums) {
            if (num & diff_bit) {
                // Numbers with this bit set.
                x ^= num;
            } else {
                // Numbers with this bit unset.
                y ^= num;
            }
        }
        
        return {x, y};
    }
};
