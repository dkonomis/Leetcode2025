from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    """
    0025. Reverse Nodes in k-Group

    Problem:
    Given the head of a linked list, reverse the nodes of the list k at a time,
    and return the modified list. If the number of nodes is not a multiple of k,
    the remaining nodes at the end should remain as is. Do not modify node values.

    Approach:
    Use a dummy node before head for easier pointer manipulation.
    For each k-group:
        - Check if there are k nodes ahead.
        - Reverse the k nodes in place by pointer rewiring.
        - Reconnect the reversed group to the previous and next segments.
    Proceed to the next group.

    Time Complexity: O(n), where n is the number of nodes.
    Space Complexity: O(1), constant extra space.
    """

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Create a dummy node to simplify edge connections.
        dummy = ListNode(0)
        dummy.next = head
        group_prev = dummy

        while True:
            # Find the kth node from group_prev.
            kth = group_prev
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next  # Not enough nodes left.

            group_next = kth.next  # Node after the current k-group.

            # Reverse the group.
            prev = group_next
            curr = group_prev.next

            for _ in range(k):
                temp = curr.next  # Save next node.
                curr.next = prev  # Reverse pointer.
                prev = curr  # Move prev forward.
                curr = temp  # Move curr forward.

            # After reversal, connect previous group to new head.
            temp = group_prev.next  # New tail of the group after reversal.
            group_prev.next = kth  # kth is new head of reversed group.
            group_prev = temp  # Move group_prev to new tail for next iteration.

