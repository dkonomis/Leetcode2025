class Solution {
public:
    int hammingWeight(uint32_t n) {
        /**
         * Problem: 0191 - Number of 1 Bits
         * 
         * Count the number of 1 bits in the binary representation of n.
         * Also known as the Hamming weight.
         * 
         * Approach:
         * - Use Brian Kernighan's algorithm: n & (n-1) clears the rightmost 1
         * - Count how many times we can clear a 1 bit until n becomes 0
         * - This is more efficient than checking all 32 bits
         * 
         * Time complexity: O(k) where k is the number of 1 bits.
         * Space complexity: O(1) - only using a counter variable.
         */
        
        int res = 0;
        
        // Keep clearing the rightmost 1 bit until n becomes 0.
        while (n) {
            // n & (n-1) clears the rightmost 1 bit.
            n &= n - 1;
            res++;
        }
        
        return res;
    }
};
