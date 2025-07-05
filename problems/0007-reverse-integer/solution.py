class Solution:
    def reverse(self, x: int) -> int:
        """
        Problem: 0007 - Reverse Integer.

        Given a signed 32-bit integer x, return the reversed digits of x.
        If the reversed integer overflows, return 0.

        Time Complexity: O(log₁₀(n)), where n is the input number.
        Space Complexity: O(1).
        """

        INT_MIN, INT_MAX = -2**31, 2**31 - 1

        res = 0
        negative = x < 0
        x = abs(x)

        # Process each digit by popping from the right.
        while x != 0:
            digit = x % 10
            x = x // 10

            # Check for overflow before pushing digit.
            if res > (INT_MAX - digit) // 10:
                return 0

            res = res * 10 + digit

        return -res if negative else res

