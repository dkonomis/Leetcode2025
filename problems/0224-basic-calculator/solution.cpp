class Solution {
public:
    int calculate(string s) {
        /**
         * Problem: 0224 - Basic Calculator
         * 
         * Evaluate expression with +, -, parentheses, and spaces.
         * Use a stack to handle parentheses by saving the state before entering them.
         * Track current result and sign as we process the expression.
         * Convert A - B to A + (-B) to handle all operations as additions.
         * 
         * Time complexity: O(n) where n is the length of the string.
         * Space complexity: O(n) for the stack in worst case.
         */
        
        stack<int> stk;
        int res = 0;  // Current result.
        int sign = 1;  // Current sign: 1 for positive, -1 for negative.
        int i = 0;
        
        while (i < s.length()) {
            if (isdigit(s[i])) {
                // Parse the complete number.
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                // Add number to result with current sign.
                res += sign * num;
                // Move back one position since outer loop will increment.
                i--;
            } else if (s[i] == '+') {
                // Set sign for next number.
                sign = 1;
            } else if (s[i] == '-') {
                // Set sign for next number.
                sign = -1;
            } else if (s[i] == '(') {
                // Save current state to stack before processing parentheses.
                stk.push(res);
                stk.push(sign);
                // Reset for new sub-expression.
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                // Pop sign before parentheses.
                int prev_sign = stk.top();
                stk.pop();
                // Pop result before parentheses.
                int prev_res = stk.top();
                stk.pop();
                // Apply the sign to current result and add to previous result.
                res = prev_res + prev_sign * res;
            }
            // Skip spaces.
            
            i++;
        }
        
        return res;
    }
};
