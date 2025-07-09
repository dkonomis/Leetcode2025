class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        Problem: 0061 - Rotate List

        Given the head of a singly linked list, rotate the list to the right by k places.

        Approach:
        - First, count the length of the list.
        - Reduce k by taking k modulo length, since rotating by length has no effect.
        - If k is 0 or list is empty or has one node, return head directly.
        - Find the new tail: (length - k - 1)-th node.
        - The new head is the next node.
        - Break the link after the new tail and reconnect the old tail to the old head.

        Time complexity: O(n), where n is the number of nodes in the list.
        Space complexity: O(1), constant extra space.
        """
        if not head or not head.next or k == 0:
            return head  # No rotation needed.

        # First, compute the length of the list.
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1

        k %= length  # Normalize k within bounds.
        if k == 0:
            return head  # No rotation after modulo.

        # Find the new tail at (length - k - 1)-th position.
        new_tail = head
        for _ in range(length - k - 1):
            new_tail = new_tail.next

        # New head is the next node.
        new_head = new_tail.next

        # Break the link and rotate.
        new_tail.next = None
        tail.next = head  # Connect old tail to old head.

        return new_head

