# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Problem: 0143 - Reorder List
        
        Given a linked list L0 → L1 → ... → L(n-1) → Ln,
        reorder it to: L0 → Ln → L1 → L(n-1) → L2 → L(n-2) → ...
        
        Approach:
        1. Find the middle of the linked list using slow/fast pointers.
        2. Reverse the second half of the list.
        3. Merge the two halves by alternating nodes.
        
        Time complexity: O(n).
        Space complexity: O(1).
        """
        if not head or not head.next:
            return
        
        # Find the middle of the linked list.
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # Split the list into two halves.
        second_half = slow.next
        slow.next = None
        
        # Reverse the second half.
        prev = None
        curr = second_half
        while curr:
            # Store next node before we change the pointer.
            next_temp = curr.next
            # Reverse the current node's pointer.
            curr.next = prev
            # Move prev and curr one step forward.
            prev = curr
            curr = next_temp
        
        # Merge the two halves by alternating nodes.
        first = head
        second = prev
        while second:
            # Save next pointers.
            first_next = first.next
            second_next = second.next
            
            # Reorder connections.
            first.next = second
            second.next = first_next
            
            # Move to next pair.
            first = first_next
            second = second_next
