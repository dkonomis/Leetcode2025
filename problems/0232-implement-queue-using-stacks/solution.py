class MyQueue:
    """
    Problem: 0232 - Implement Queue using Stacks
    
    Implement FIFO queue using two stacks.
    Use input stack for push operations and output stack for pop/peek.
    Transfer elements from input to output stack when needed.
    This achieves amortized O(1) time for all operations.
    
    Time complexity: O(1) amortized for all operations.
    Space complexity: O(n) where n is the number of elements.
    """

    def __init__(self):
        # Input stack for new elements.
        self.input_stack = []
        # Output stack for dequeue operations.
        self.output_stack = []

    def push(self, x: int) -> None:
        # Always push new elements to input stack.
        self.input_stack.append(x)

    def pop(self) -> int:
        # Ensure output stack has elements.
        self._move_input_to_output()
        # Pop from output stack (front of queue).
        return self.output_stack.pop()

    def peek(self) -> int:
        # Ensure output stack has elements.
        self._move_input_to_output()
        # Return top of output stack without removing.
        return self.output_stack[-1]

    def empty(self) -> bool:
        # Queue is empty if both stacks are empty.
        return len(self.input_stack) == 0 and len(self.output_stack) == 0
    
    def _move_input_to_output(self) -> None:
        # Transfer elements only when output stack is empty.
        if not self.output_stack:
            # Move all elements from input to output.
            # This reverses the order, making LIFO become FIFO.
            while self.input_stack:
                self.output_stack.append(self.input_stack.pop())


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
