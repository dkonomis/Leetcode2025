# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        """
        Problem: 0234 - Palindrome Linked List
        
        Check if linked list is palindrome using O(1) space.
        Find middle using fast/slow pointers, reverse second half, compare.
        
        Time complexity: O(n) where n is the number of nodes.
        Space complexity: O(1).
        """
        if not head or not head.next:
            return True
        
        # Find middle of the list using fast and slow pointers.
        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # Reverse the second half of the list.
        second_half = self.reverse_list(slow.next)
        
        # Compare first half with reversed second half.
        first_half = head
        while second_half:
            if first_half.val != second_half.val:
                return False
            first_half = first_half.next
            second_half = second_half.next
        
        return True
    
    def reverse_list(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """Reverse a linked list and return new head."""
        prev = None
        current = head
        
        while current:
            # Save next node.
            next_temp = current.next
            # Reverse the link.
            current.next = prev
            # Move pointers forward.
            prev = current
            current = next_temp
        
        return prev
