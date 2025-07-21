class MinStack:
    def __init__(self):
        """
        Problem: 0155 - Min Stack
        
        Design a stack with O(1) push, pop, top, and getMin operations.
        
        Approach:
        Use two stacks - one for values, one for minimums.
        Min stack stores the minimum value at each state of the main stack.
        This allows O(1) retrieval of minimum at any time.
        
        Time complexity: O(1) for all operations.
        Space complexity: O(n) for storing n elements.
        """
        self.stack = []      # Main stack for values.
        self.min_stack = []  # Stack to track minimums.

    def push(self, val: int) -> None:
        """Push value onto stack and update minimum."""
        # Push value to main stack.
        self.stack.append(val)
        
        # Push new minimum to min stack.
        # If min_stack is empty, val is the minimum.
        # Otherwise, minimum is the smaller of val and current min.
        if not self.min_stack:
            self.min_stack.append(val)
        else:
            self.min_stack.append(min(val, self.min_stack[-1]))

    def pop(self) -> None:
        """Remove top element from both stacks."""
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        """Get top element of stack."""
        return self.stack[-1]

    def getMin(self) -> int:
        """Get minimum element in O(1) time."""
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
