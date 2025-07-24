from collections import deque

class MyStack:
    """
    Problem: 0225 - Implement Stack using Queues
    
    Implement LIFO stack using only queue operations.
    Use one queue and rotate elements after each push to maintain stack order.
    After pushing x, move all elements before x to the back.
    
    Time complexity: O(n) for push, O(1) for pop/top/empty.
    Space complexity: O(n) where n is the number of elements.
    """

    def __init__(self):
        # Use deque as queue (append to add to back, popleft to remove from front).
        self.queue = deque()

    def push(self, x: int) -> None:
        # Get current size before adding new element.
        size = len(self.queue)
        
        # Add new element to back of queue.
        self.queue.append(x)
        
        # Rotate queue to move new element to front.
        # Move all old elements to the back.
        for _ in range(size):
            # Remove from front and add to back.
            self.queue.append(self.queue.popleft())

    def pop(self) -> int:
        # Remove and return front element (which is stack top).
        return self.queue.popleft()

    def top(self) -> int:
        # Return front element without removing (which is stack top).
        return self.queue[0]

    def empty(self) -> bool:
        # Check if queue is empty.
        return len(self.queue) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
