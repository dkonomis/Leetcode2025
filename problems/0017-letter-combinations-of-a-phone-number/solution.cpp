#include <vector>
#include <string>
#include <unordered_map>

class Solution {
private:
    std::vector<std::string> combinations;  // Stores the final result.
    std::unordered_map<char, std::string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    std::string phoneDigits;  // Stores the original input digits for recursive access.

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        /*
        Problem 0017 – Letter Combinations of a Phone Number.

        Given a string containing digits from 2 to 9, return all possible letter combinations
        that the number could represent, based on the telephone keypad.

        Return the answer in any order.

        Time Complexity  : O(4^n × n), where n is the length of the input string.
                           Each digit contributes up to 4 letters, and we build strings of length n.
        Space Complexity : O(n) recursion depth, or O(4^n × n) including output.
        */

        if (digits.empty()) {
            return combinations;  // Return empty if no digits are provided.
        }

        phoneDigits = digits;
        std::string path;  // Holds current path during backtracking.
        backtrack(0, path);
        return combinations;
    }

private:
    void backtrack(int index, std::string& path) {
        // If we've constructed a full combination, add it to the result.
        if (path.length() == phoneDigits.length()) {
            combinations.push_back(path);
            return;
        }

        // Get the possible letters corresponding to the current digit.
        const std::string& possibleLetters = letters[phoneDigits[index]];

        for (char letter : possibleLetters) {
            path.push_back(letter);            // Choose a letter.
            backtrack(index + 1, path);        // Recurse to the next digit.
            path.pop_back();                   // Backtrack by removing the last letter.
        }
    }
};

