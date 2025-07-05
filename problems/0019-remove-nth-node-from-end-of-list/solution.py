from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """
        Problem 0019 – Remove Nth Node From End of List.

        Use two pointers to perform a one-pass solution.
        First, advance the `first` pointer n steps ahead.
        Then move both `first` and `second` until `first` reaches the end.
        At this point, `second` will be just before the node to remove.

        Time Complexity  : O(L), where L is the length of the linked list.
        Space Complexity : O(1), constant space used.
        """

        # Create a dummy node that points to the head.
        # This simplifies deletion logic (including when deleting head).
        dummy = ListNode(0, head)

        first = dummy
        second = dummy

        # Advance `first` n + 1 steps ahead so that there is a gap of n
        # between `first` and `second`.
        for _ in range(n + 1):
            first = first.next

        # Move both pointers until `first` reaches the end.
        while first:
            first = first.next
            second = second.next

        # Now `second` is just before the node we want to remove.
        second.next = second.next.next

        # Return the head of the modified list.
        return dummy.next

