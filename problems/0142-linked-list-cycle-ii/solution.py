# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Problem: 0142 - Linked List Cycle II
        
        Find the node where cycle begins using extended Floyd's algorithm.
        
        Approach:
        1. Phase 1: Use Floyd's algorithm to detect cycle and find meeting point.
        2. Phase 2: Reset one pointer to head, move both at same speed until they meet.
        3. Meeting point in phase 2 is the cycle start (mathematical property).
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(1) using only constant extra space.
        """
        if not head or not head.next:
            return None
        
        # Phase 1: Detect cycle using Floyd's algorithm.
        slow = head
        fast = head
        
        # Find meeting point inside cycle.
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            if slow == fast:
                break
        else:
            # No cycle found.
            return None
        
        # Phase 2: Find cycle start.
        # Reset one pointer to head, move both at same speed.
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        
        # Both pointers now point to cycle start.
        return slow
