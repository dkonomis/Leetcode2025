# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        """
        Problem: 0203 - Remove Linked List Elements
        
        Given head of linked list and value val, remove all nodes with Node.val == val
        and return the new head.
        
        Approach: Use dummy node to handle edge cases. Traverse list with prev and
        current pointers. When current.val == val, skip the node by updating prev.next.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(1).
        """
        # Create dummy node to handle edge case where head needs to be removed.
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        current = head
        
        # Traverse the linked list.
        while current:
            if current.val == val:
                # Skip the current node by updating prev.next.
                prev.next = current.next
            else:
                # Move prev pointer only when we don't remove current node.
                prev = current
            
            # Always move current pointer to next node.
            current = current.next
        
        # Return the new head (dummy.next handles all edge cases).
        return dummy.next
