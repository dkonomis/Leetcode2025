#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        /*
        Problem: 0008 - String to Integer (atoi).

        Parses a string and returns a 32-bit signed integer according to rules:
        - Skips leading whitespaces.
        - Optional '+' or '-' sign.
        - Reads digits until a non-digit character or end of string.
        - Clamps to INT_MAX or INT_MIN if the value overflows/underflows.

        Time Complexity: O(n)
        Space Complexity: O(1)
        */

        int i = 0;
        int n = s.length();
        int result = 0;
        int sign = 1;

        // Step 1: Skip leading whitespaces.
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional '+' or '-' sign.
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Process digit characters.
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Check for overflow and underflow.
            if (sign == 1) {
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                    return INT_MAX;
                }
            } else {
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit >= 8)) {
                    return INT_MIN;
                }
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

