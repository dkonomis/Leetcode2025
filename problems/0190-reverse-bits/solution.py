class Solution:
    def reverseBits(self, n: int) -> int:
        """
        Problem: 0190 - Reverse Bits
        
        Reverse the bits of a 32-bit unsigned integer.
        
        Approach:
        - Extract each bit from n starting from the least significant bit
        - Place each bit in the reversed position in the result
        - Use bit manipulation: AND to extract, OR to set, shift to move
        
        Time complexity: O(1) - always 32 iterations.
        Space complexity: O(1) - only using a single variable.
        """
        res = 0
        
        # Process all 32 bits.
        for i in range(32):
            # Extract the least significant bit of n.
            bit = n & 1
            
            # Place this bit at position (31 - i) in res.
            res |= bit << (31 - i)
            
            # Right shift n to process the next bit.
            n >>= 1
        
        return res
