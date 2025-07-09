class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Problem: 0082 - Remove Duplicates from Sorted List II

        Given the head of a sorted linked list, delete all nodes that have duplicate values,
        keeping only distinct numbers from the original list.

        Approach:
        - Use a dummy node pointing to the head to simplify edge cases.
        - Traverse the list with a 'prev' pointer that always lags one step behind 'head'.
        - When a duplicate cluster is detected (head.val == head.next.val), skip the entire group.
        - Otherwise, move 'prev' forward.
        - Always advance 'head' to continue traversal.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(1).
        """
        dummy = ListNode(0)  # Dummy node before the head.
        dummy.next = head

        prev = dummy  # Previous distinct node.

        while head:
            # Detect duplicates by checking the next value.
            if head.next and head.val == head.next.val:
                # Skip all nodes with the same value.
                while head.next and head.val == head.next.val:
                    head = head.next
                # Skip the entire duplicate cluster.
                prev.next = head.next
            else:
                # Move prev only if no duplicate was found.
                prev = prev.next

            # Move forward in all cases to continue traversal.
            head = head.next

        return dummy.next

