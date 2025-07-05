#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        /*
        Problem 0012 – Integer to Roman.

        Given an integer between 1 and 3999, convert it to a Roman numeral.

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
        - Only I, X, C, M can be repeated (up to 3 times).
        - V, L, D cannot be repeated.
        - Subtractive forms are used instead of 4-symbol repetition.

        Approach:
        Use a greedy algorithm with a descending list of (value, symbol) pairs.
        At each step, subtract the largest possible value from `num` and append the symbol.

        Time Complexity  : O(1)
        Space Complexity : O(1)
        */

        // List of value-symbol pairs in descending order,
        // including all subtractive combinations.
        std::vector<std::pair<int, std::string>> val_to_sym = {
            {1000, "M"}, {900, "CM"},
            {500, "D"},  {400, "CD"},
            {100, "C"},  {90, "XC"},
            {50, "L"},   {40, "XL"},
            {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},
            {1, "I"}
        };

        std::string res;

        // Iterate through the pairs greedily.
        for (const auto& [value, symbol] : val_to_sym) {
            while (num >= value) {
                res += symbol;    // Append symbol to result string.
                num -= value;     // Subtract value from num.
            }
            if (num == 0) {
                break;            // Early exit once num is reduced to 0.
            }
        }

        return res;
    }
};

