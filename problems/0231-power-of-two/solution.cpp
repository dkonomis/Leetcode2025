class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
         * Problem: 0231 - Power of Two
         * 
         * Check if n is a power of 2 using bit manipulation.
         * A power of 2 has exactly one bit set in binary representation.
         * Trick: n & (n-1) removes the rightmost set bit.
         * If n is power of 2, this operation results in 0.
         * 
         * Time complexity: O(1).
         * Space complexity: O(1).
         */
        
        // Power of 2 must be positive.
        if (n <= 0) {
            return false;
        }
        
        // Check if n has exactly one bit set.
        // Example: 8 = 1000, 7 = 0111, 8 & 7 = 0000.
        // Example: 6 = 0110, 5 = 0101, 6 & 5 = 0100 (not 0).
        return (n & (n - 1)) == 0;
    }
};
