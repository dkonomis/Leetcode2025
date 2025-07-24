class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        """
        Problem: 0241 - Different Ways to Add Parentheses
        
        Compute all possible results by adding parentheses in different ways.
        Use divide and conquer: split at each operator and recursively solve.
        For each operator, compute all results from left and right subexpressions.
        Combine them using the operator.
        
        Time complexity: O(n * 2^n) where n is the number of operators.
        Space complexity: O(2^n) for storing all possible results.
        """
        # Memoization to avoid recomputing same subexpressions.
        memo = {}
        
        def compute(expr):
            # Check if already computed.
            if expr in memo:
                return memo[expr]
            
            res = []
            
            # Try splitting at each operator.
            for i in range(len(expr)):
                if expr[i] in '+-*':
                    # Split expression at operator.
                    left_expr = expr[:i]
                    right_expr = expr[i + 1:]
                    
                    # Recursively compute all results for left and right.
                    left_results = compute(left_expr)
                    right_results = compute(right_expr)
                    
                    # Combine all left and right results using current operator.
                    for left in left_results:
                        for right in right_results:
                            if expr[i] == '+':
                                res.append(left + right)
                            elif expr[i] == '-':
                                res.append(left - right)
                            elif expr[i] == '*':
                                res.append(left * right)
            
            # Base case: no operators found, expr is just a number.
            if not res:
                res.append(int(expr))
            
            # Save to memo and return.
            memo[expr] = res
            return res
        
        return compute(expression)
