class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
         * Problem: 0201 - Bitwise AND of Numbers Range
         * Given two integers left and right, return the bitwise AND of all numbers
         * in the range [left, right], inclusive.
         * 
         * Approach: Find the common binary prefix of left and right. When we AND
         * consecutive numbers, bits that differ between left and right will become 0.
         * Only the common prefix bits remain as 1.
         * 
         * Time complexity: O(log n) where n is the maximum of left and right.
         * Space complexity: O(1).
         */
        
        int shift = 0;
        
        // Find the common prefix by right-shifting until left equals right.
        while (left != right) {
            left >>= 1;   // Right shift left by 1 bit.
            right >>= 1;  // Right shift right by 1 bit.
            shift++;      // Count how many shifts we performed.
        }
        
        // Left-shift the common prefix back to original position.
        return left << shift;
    }
};
