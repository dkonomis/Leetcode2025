# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Problem: 0141 - Linked List Cycle
        
        Detect if linked list has a cycle using Floyd's algorithm.
        
        Approach:
        1. Use two pointers: slow (1 step) and fast (2 steps).
        2. If there's a cycle, fast will eventually catch up to slow.
        3. If no cycle, fast will reach the end (None).
        4. Floyd's Tortoise and Hare algorithm.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(1) using only constant extra space.
        """
        if not head or not head.next:
            return False
        
        slow = head
        fast = head
        
        # Move pointers until they meet or fast reaches end.
        while fast and fast.next:
            slow = slow.next        # Tortoise: 1 step.
            fast = fast.next.next   # Hare: 2 steps.
            
            # If pointers meet, there's a cycle.
            if slow == fast:
                return True
        
        # Fast reached end, no cycle.
        return False
