# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        """
        Problem: 0160 - Intersection of Two Linked Lists
        
        Find the node where two linked lists intersect.
        
        Approach:
        Two pointers traverse both lists. When a pointer reaches the end,
        redirect it to the head of the other list. They'll meet at intersection
        or both become None if no intersection.
        
        Why it works: Each pointer travels distance a + c + b, where:
        - a = length of A before intersection
        - b = length of B before intersection  
        - c = length of common part
        
        Time complexity: O(m + n).
        Space complexity: O(1).
        """
        if not headA or not headB:
            return None
        
        # Initialize two pointers.
        ptrA = headA
        ptrB = headB
        
        # Traverse until pointers meet.
        while ptrA != ptrB:
            # Move to next node or switch to other list's head.
            ptrA = ptrA.next if ptrA else headB
            ptrB = ptrB.next if ptrB else headA
        
        # Either both are None (no intersection) or both point to intersection.
        return ptrA
