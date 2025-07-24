class Solution {
public:
    int calculate(string s) {
        /**
         * Problem: 0227 - Basic Calculator II
         * 
         * Evaluate expression with +, -, *, / operators.
         * Use a stack to handle operator precedence: * and / before + and -.
         * Process multiplication and division immediately, delay addition and subtraction.
         * 
         * Time complexity: O(n) where n is the length of the string.
         * Space complexity: O(n) for the stack.
         */
        
        if (s.empty()) {
            return 0;
        }
        
        stack<int> stk;
        int num = 0;
        // Start with '+' so first number is treated as positive.
        char op = '+';
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                // Build the current number.
                num = num * 10 + (c - '0');
            }
            
            // Process when we hit an operator or reach the end.
            // Skip spaces unless it's the last character.
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.length() - 1) {
                // Process the previous operator with current number.
                if (op == '+') {
                    // Push positive number to stack.
                    stk.push(num);
                } else if (op == '-') {
                    // Push negative number to stack.
                    stk.push(-num);
                } else if (op == '*') {
                    // Pop last number, multiply, push result back.
                    int prev = stk.top();
                    stk.pop();
                    int res = prev * num;
                    stk.push(res);
                } else if (op == '/') {
                    // Pop last number, divide, push result back.
                    int prev = stk.top();
                    stk.pop();
                    // Integer division in C++ truncates toward zero.
                    int res = prev / num;
                    stk.push(res);
                }
                
                // Update operator for next number if current char is operator.
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    op = c;
                }
                // Reset number for next iteration.
                num = 0;
            }
        }
        
        // Sum all numbers in stack for final result.
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        
        return res;
    }
};
