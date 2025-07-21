# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Problem: 0148 - Sort List
        
        Sort a linked list in ascending order using merge sort.
        
        Approach:
        Use merge sort (divide and conquer):
        1. Split list in half using slow/fast pointers
        2. Recursively sort both halves
        3. Merge the sorted halves
        
        Time complexity: O(n log n).
        Space complexity: O(log n) for recursion stack.
        """
        if not head or not head.next:
            return head
        
        # Find the middle using slow/fast pointers.
        slow = head
        fast = head
        prev = None  # Need to cut the list in half.
        
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        # Cut the list into two halves.
        prev.next = None
        
        # Recursively sort both halves.
        left = self.sortList(head)
        right = self.sortList(slow)
        
        # Merge the sorted halves.
        return self.merge(left, right)
    
    def merge(self, left: Optional[ListNode], right: Optional[ListNode]) -> Optional[ListNode]:
        """Merge two sorted linked lists."""
        dummy = ListNode(0)
        curr = dummy
        
        # Merge nodes in sorted order.
        while left and right:
            if left.val <= right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next
            curr = curr.next
        
        # Attach remaining nodes.
        if left:
            curr.next = left
        if right:
            curr.next = right
        
        return dummy.next
