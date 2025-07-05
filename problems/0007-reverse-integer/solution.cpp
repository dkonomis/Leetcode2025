#include <climits>

class Solution {
public:
    int reverse(int x) {
        /*
        Problem: 0007 - Reverse Integer.

        Reverse digits of a 32-bit signed integer.
        Return 0 if reversing causes overflow.

        Time Complexity: O(log₁₀(n)).
        Space Complexity: O(1).
        */

        int res = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow.
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            res = res * 10 + digit;
        }

        return res;
    }
};


