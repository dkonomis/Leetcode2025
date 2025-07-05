#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(const std::string& s) {
        /*
        Problem 0020 – Valid Parentheses.

        Use a stack to match every closing bracket with the most recent unmatched opening bracket.
        If a mismatch occurs or the stack is not empty at the end, return false.

        Time Complexity  : O(n), where n is the length of the string.
        Space Complexity : O(n), for the stack.
        */

        // Map each closing bracket to its corresponding opening bracket.
        std::unordered_map<char, char> bracket_map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        std::stack<char> stack;

        for (char ch : s) {
            // If it's a closing bracket.
            if (bracket_map.count(ch)) {
                // Get the top of the stack if not empty, else use a dummy.
                char top = stack.empty() ? '#' : stack.top();
                if (!stack.empty()) stack.pop();

                // Check if it matches the expected opening bracket.
                if (top != bracket_map[ch]) {
                    return false;
                }
            } else {
                // It's an opening bracket.
                stack.push(ch);
            }
        }

        // If the stack is empty, all brackets were matched.
        return stack.empty();
    }
};

