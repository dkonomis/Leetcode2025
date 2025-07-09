#include <string>
using namespace std;

class Solution {
public:
    /*
    Problem: 0065 - Valid Number

    Given a string s, return whether it represents a valid number.

    Approach:
    - Simulate a finite state machine with boolean flags.
    - Track if we've seen a digit, a dot '.', or an exponent 'e'/'E'.
    - A sign '+' or '-' is valid only at the beginning or immediately after 'e'/'E'.
    - A dot is allowed only once and never after an exponent.
    - An exponent is allowed only once and must follow a valid number.
    - After an exponent, digits are mandatory.

    Time Complexity: O(n), where n = s.length()
    Space Complexity: O(1)
    */
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;

        // Trim leading spaces.
        while (i < n && s[i] == ' ') i++;
        // Trim trailing spaces.
        int j = n - 1;
        while (j >= 0 && s[j] == ' ') j--;

        if (i > j) return false;  // All spaces.

        bool seen_digit = false;
        bool seen_dot = false;
        bool seen_exp = false;

        for (int k = i; k <= j; ++k) {
            char c = s[k];

            if (isdigit(c)) {
                seen_digit = true;
            }
            else if (c == '+' || c == '-') {
                // Sign must be at the beginning or just after an exponent.
                if (k != i && !(s[k - 1] == 'e' || s[k - 1] == 'E')) {
                    return false;
                }
            }
            else if (c == '.') {
                // Dot is allowed only once and only before any exponent.
                if (seen_dot || seen_exp) {
                    return false;
                }
                seen_dot = true;
            }
            else if (c == 'e' || c == 'E') {
                // Exponent must come after a digit and only once.
                if (seen_exp || !seen_digit) {
                    return false;
                }
                seen_exp = true;
                seen_digit = false;  // We must see digits after exponent.
            }
            else {
                return false;  // Invalid character.
            }
        }

        return seen_digit;
    }
};

