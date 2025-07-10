class Solution:
    def grayCode(self, n: int) -> List[int]:
        """
        Problem: 0089 - Gray Code

        Given a non-negative integer n, generate a sequence of 2^n integers
        representing the Gray code. A Gray code sequence has the property that
        successive numbers differ by exactly one bit.

        Approach:
        - Use the reflect-and-prefix construction.
        - Start with n = 0: base case [0].
        - For each i from 1 to n:
            * Reflect the current list (reverse it).
            * Prefix all reflected values with a 1 at the i-th bit position
              (i.e., add 1 << (i-1) to each value).
            * Append these values to the original list.

        This preserves the one-bit-difference property throughout the sequence.

        Time complexity: O(2^n)
        Space complexity: O(2^n)
        """
        res = [0]  # Base case for n = 0.

        for i in range(n):
            # Current bit mask for the new MSB (e.g., 1 << i).
            bit = 1 << i

            # Reflect the current list and prefix each number with '1' at position i.
            for j in reversed(res):
                res.append(j | bit)

        return res

