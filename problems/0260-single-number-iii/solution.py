class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        """
        Problem: 0260 - Single Number III
        
        Find two single numbers using XOR and bit manipulation.
        1. XOR all numbers to get x ^ y (pairs cancel out).
        2. Find a bit where x and y differ (any set bit in x ^ y).
        3. Partition numbers by this bit into two groups.
        4. XOR each group to get x and y separately.
        
        Time complexity: O(n) with two passes through the array.
        Space complexity: O(1) using only constant extra space.
        """
        # Step 1: XOR all numbers to get x ^ y.
        xor_all = 0
        for num in nums:
            xor_all ^= num
        
        # Step 2: Find rightmost set bit (where x and y differ).
        # x & -x isolates the rightmost set bit.
        diff_bit = xor_all & -xor_all
        
        # Step 3 & 4: Partition and XOR each group.
        x = y = 0
        for num in nums:
            if num & diff_bit:
                # Numbers with this bit set.
                x ^= num
            else:
                # Numbers with this bit unset.
                y ^= num
        
        return [x, y]
