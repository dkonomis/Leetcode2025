class Solution:
    def calculate(self, s: str) -> int:
        """
        Problem: 0227 - Basic Calculator II
        
        Evaluate expression with +, -, *, / operators.
        Use a stack to handle operator precedence: * and / before + and -.
        Process multiplication and division immediately, delay addition and subtraction.
        
        Time complexity: O(n) where n is the length of the string.
        Space complexity: O(n) for the stack.
        """
        if not s:
            return 0
        
        stack = []
        num = 0
        # Start with '+' so first number is treated as positive.
        operator = '+'
        
        for i, char in enumerate(s):
            if char.isdigit():
                # Build the current number.
                num = num * 10 + int(char)
            
            # Process when we hit an operator or reach the end.
            # Skip spaces unless it's the last character.
            if char in '+-*/' or i == len(s) - 1:
                # Process the previous operator with current number.
                if operator == '+':
                    # Push positive number to stack.
                    stack.append(num)
                elif operator == '-':
                    # Push negative number to stack.
                    stack.append(-num)
                elif operator == '*':
                    # Pop last number, multiply, push result back.
                    prev = stack.pop()
                    res = prev * num
                    stack.append(res)
                elif operator == '/':
                    # Pop last number, divide, push result back.
                    prev = stack.pop()
                    # Use int() for truncation toward zero.
                    res = int(prev / num)
                    stack.append(res)
                
                # Update operator for next number if current char is operator.
                if char in '+-*/':
                    operator = char
                # Reset number for next iteration.
                num = 0
        
        # Sum all numbers in stack for final result.
        return sum(stack)
