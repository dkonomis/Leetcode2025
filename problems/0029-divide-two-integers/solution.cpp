#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        /*
        0029. Divide Two Integers

        Problem:
        Divide two integers without using multiplication, division, or mod, truncating toward zero.
        Clamp the result to the 32-bit signed range.

        Approach:
        • Handle INT_MIN overflow cases up front (−2³¹ ÷ −1 or +1).
        • Convert both operands to negatives to avoid negating INT_MIN.
        • Subtract largest possible multiples of divisor from dividend.
        • Accumulate quotient (as a negative number), then flip sign if needed.

        Time Complexity:  O(log n).
        Space Complexity: O(1).
        */

        // Handle overflow: INT_MIN / -1 overflows 32-bit int.
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Handle overflow: INT_MIN / 1 would cause -INT_MIN, which is UB.
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        // Determine whether the final result should be negative.
        bool negative = (dividend < 0) != (divisor < 0);

        // Convert both numbers to negative to avoid negating INT_MIN.
        dividend = dividend > 0 ? -dividend : dividend;
        divisor  = divisor  > 0 ? -divisor  : divisor;

        int quotient = 0;  // Accumulate the result here, always kept negative.

        // Keep subtracting multiples of divisor from dividend.
        while (dividend <= divisor) {
            int value = divisor;        // Start with the original divisor.
            int power_of_two = 1;       // Corresponds to the multiple we are subtracting.

            // Double the value until it is too large or doesn't fit in dividend.
            while (value >= (INT_MIN >> 1) && dividend <= (value << 1)) {
                value <<= 1;            // value = value * 2.
                power_of_two <<= 1;     // power_of_two = power_of_two * 2.
            }

            // Subtract the largest fitting chunk and accumulate the quotient.
            dividend -= value;          // Reduce the dividend.
            quotient -= power_of_two;   // Subtract corresponding power from quotient.
        }

        // If result should be positive, safely negate the (negative) quotient.
        return negative ? quotient : -quotient;
    }
};

