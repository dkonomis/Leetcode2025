class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        """
        Problem: 0092 - Reverse Linked List II

        Given the head of a singly linked list and two integers left and right,
        reverse the nodes between positions left and right (1-indexed), and return the modified list.

        Approach:
        - Use a dummy node to simplify edge cases (e.g., reversing from head).
        - Traverse to the node just before position 'left'.
        - Reverse the sublist between 'left' and 'right' using standard in-place reversal.
        - Reconnect the reversed sublist back into the list.

        Time complexity: O(n)
        Space complexity: O(1)
        """
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        # Traverse to the node just before position 'left'.
        for _ in range(left - 1):
            prev = prev.next

        # Reverse the sublist between left and right.
        reverse_prev = prev
        current = prev.next
        prev = None

        # Perform in-place reversal of the sublist.
        for _ in range(right - left + 1):
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node

        # Reconnect the reversed sublist.
        reverse_prev.next.next = current
        reverse_prev.next = prev

        return dummy.next

