#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(const std::string& s) {
        /*
        Problem 0013 – Roman to Integer.

        Given a Roman numeral string representing an integer in the range [1, 3999],
        convert it to its corresponding integer value.

        Roman numeral symbols:
            I = 1, V = 5, X = 10, L = 50,
            C = 100, D = 500, M = 1000

        Subtractive forms are used for:
            4   → IV
            9   → IX
            40  → XL
            90  → XC
            400 → CD
            900 → CM

        Rules:
        - Read from right to left.
        - If the current value is less than the next, subtract it.
        - Otherwise, add it.

        Time Complexity  : O(n), where n = s.length().
        Space Complexity : O(1), constant-size hash table.
        */

        // Mapping of Roman numerals to integer values.
        std::unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;          // Final result.
        int prev = 0;           // Value of previous character.

        // Iterate from the end of the string to the beginning.
        for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
            int curr = roman[s[i]];  // Current symbol's value.
            if (curr < prev) {
                total -= curr;       // Subtractive case.
            } else {
                total += curr;       // Additive case.
            }
            prev = curr;             // Update previous value.
        }

        return total;
    }
};

