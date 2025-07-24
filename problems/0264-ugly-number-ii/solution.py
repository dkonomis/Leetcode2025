class Solution:
    def nthUglyNumber(self, n: int) -> int:
        """
        Problem: 0264 - Ugly Number II
        
        Find the nth ugly number where ugly numbers have only 2, 3, 5 as prime factors.
        
        Approach: Dynamic programming with three pointers. Maintain an array of ugly numbers
        and use three pointers to track positions for multiplying by 2, 3, and 5. At each
        step, choose the minimum of the three candidates and advance the corresponding pointer(s).
        
        Time complexity: O(n).
        Space complexity: O(n).
        """
        # Initialize array to store ugly numbers.
        ugly = [0] * n
        ugly[0] = 1
        
        # Three pointers for multiples of 2, 3, and 5.
        i2 = i3 = i5 = 0
        
        # Generate ugly numbers from index 1 to n-1.
        for i in range(1, n):
            # Calculate next candidates.
            next_multiple_of_2 = ugly[i2] * 2
            next_multiple_of_3 = ugly[i3] * 3
            next_multiple_of_5 = ugly[i5] * 5
            
            # Choose the minimum as the next ugly number.
            ugly[i] = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5)
            
            # Move pointer(s) forward if their value was chosen.
            if ugly[i] == next_multiple_of_2:
                i2 += 1
            if ugly[i] == next_multiple_of_3:
                i3 += 1
            if ugly[i] == next_multiple_of_5:
                i5 += 1
        
        # Return the nth ugly number.
        return ugly[n - 1]
