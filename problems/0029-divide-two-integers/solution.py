class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """
        0029. Divide Two Integers

        Problem:
        Given two integers dividend and divisor, divide them without using multiplication, division, or mod operators.
        Truncate the result toward zero. Return the quotient, clamped to the 32-bit signed integer range.

        Approach:
        Use repeated subtraction in exponentially growing chunks:
            - Convert both numbers to negatives to handle edge cases and avoid overflow.
            - For each loop iteration, find the largest multiple of divisor (by doubling) that can fit into the current dividend.
            - Subtract that multiple and add the corresponding power-of-two to the quotient.
        This simulates long division using binary shifts.

        Time Complexity: O(log n), where n is the absolute value of the dividend.
        Space Complexity: O(1), constant extra space.
        """

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        negative = (dividend < 0) != (divisor < 0)

        dividend = -abs(dividend)
        divisor = -abs(divisor)

        quotient = 0

        while dividend <= divisor:
            power_of_two = 1
            value = divisor

            while value >= (INT_MIN >> 1) and dividend <= value + value:
                value += value
                power_of_two += power_of_two

            dividend -= value
            quotient += power_of_two

        return -quotient if negative else quotient

