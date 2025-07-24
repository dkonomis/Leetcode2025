class Solution:
    def calculate(self, s: str) -> int:
        """
        Problem: 0224 - Basic Calculator
        
        Evaluate expression with +, -, parentheses, and spaces.
        Use a stack to handle parentheses by saving the state before entering them.
        Track current result and sign as we process the expression.
        Convert A - B to A + (-B) to handle all operations as additions.
        
        Time complexity: O(n) where n is the length of the string.
        Space complexity: O(n) for the stack in worst case.
        """
        stack = []
        res = 0  # Current result.
        sign = 1  # Current sign: 1 for positive, -1 for negative.
        i = 0
        
        while i < len(s):
            if s[i].isdigit():
                # Parse the complete number.
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                # Add number to result with current sign.
                res += sign * num
                # Move back one position since outer loop will increment.
                i -= 1
            elif s[i] == '+':
                # Set sign for next number.
                sign = 1
            elif s[i] == '-':
                # Set sign for next number.
                sign = -1
            elif s[i] == '(':
                # Save current state to stack before processing parentheses.
                stack.append(res)
                stack.append(sign)
                # Reset for new sub-expression.
                res = 0
                sign = 1
            elif s[i] == ')':
                # Pop sign before parentheses.
                prev_sign = stack.pop()
                # Pop result before parentheses.
                prev_res = stack.pop()
                # Apply the sign to current result and add to previous result.
                res = prev_res + prev_sign * res
            # Skip spaces.
            
            i += 1
        
        return res
