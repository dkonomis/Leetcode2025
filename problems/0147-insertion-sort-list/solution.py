# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Problem: 0147 - Insertion Sort List
        
        Sort a linked list using insertion sort algorithm.
        Build a sorted list by taking nodes one by one and inserting
        them at the correct position.
        
        Approach:
        Use a dummy node to simplify insertions at the head.
        For each node, find its correct position in the sorted portion
        and insert it there. Keep track of the last sorted node for optimization.
        
        Time complexity: O(n^2) worst case, better in practice for partially sorted.
        Space complexity: O(1).
        """
        if not head or not head.next:
            return head
        
        # Create dummy node pointing to the sorted portion.
        dummy = ListNode(0)
        dummy.next = head
        
        # Last node in the sorted portion.
        last_sorted = head
        # Current node to be inserted.
        curr = head.next
        
        while curr:
            # If curr is already in correct position (greater than last sorted).
            if curr.val >= last_sorted.val:
                last_sorted = curr
                curr = curr.next
            else:
                # Find the correct position for curr in sorted portion.
                # Start from dummy to find insertion point.
                prev = dummy
                
                # Find position where prev.next.val > curr.val.
                while prev.next.val < curr.val:
                    prev = prev.next
                
                # Remove curr from its current position.
                last_sorted.next = curr.next
                
                # Insert curr after prev.
                curr.next = prev.next
                prev.next = curr
                
                # Move to next node to process.
                curr = last_sorted.next
        
        return dummy.next
