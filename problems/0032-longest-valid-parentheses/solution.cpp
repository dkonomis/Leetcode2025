#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        0032. Longest Valid Parentheses

        Problem:
        Given a string s containing only '(' and ')', return the length of the longest 
        valid (well-formed) parentheses substring.

        Approach:
        Use a stack to track the indices of unmatched parentheses.
        Initialize the stack with -1 to handle edge cases.
        For each '(' push its index.
        For each ')', pop the stack. If the stack is empty after popping, push current index.
        Otherwise, update the max length using the distance between current index and stack top.

        Time complexity: O(n)
        Space complexity: O(n)
        */

        int max_len = 0;
        stack<int> stk;          // Stack to store indices.
        stk.push(-1);            // Base index for the first valid substring.

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);     // Push index of '('.
            } else {
                stk.pop();       // Try to match with previous '('.
                if (stk.empty()) {
                    stk.push(i); // No match found, push index as new base.
                } else {
                    max_len = max(max_len, i - stk.top());  // Update max length.
                }
            }
        }

        return max_len;
    }
};

