class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        Problem: 0150 - Evaluate Reverse Polish Notation
        
        Evaluate arithmetic expression in RPN format where operators come after operands.
        Example: "2 1 +" means 2 + 1 = 3
        
        Approach:
        Use a stack. Push numbers onto stack. When operator found,
        pop two operands, apply operation, push result back.
        Order matters for subtraction and division.
        
        Time complexity: O(n).
        Space complexity: O(n) for the stack.
        """
        stack = []
        operators = {'+', '-', '*', '/'}
        
        for token in tokens:
            if token not in operators:
                # It's a number - push to stack.
                stack.append(int(token))
            else:
                # It's an operator - pop two operands.
                # Note: second operand is popped first.
                b = stack.pop()
                a = stack.pop()
                
                # Apply operation and push result.
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                else:  # token == '/'
                    # Truncate toward zero using int().
                    stack.append(int(a / b))
        
        # Final result is the only element left.
        return stack[0]
