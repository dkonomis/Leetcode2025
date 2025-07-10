class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        """
        Problem: 0086 - Partition List

        Given the head of a linked list and a value x, rearrange the nodes such that:
        - All nodes with values less than x come before nodes with values greater than or equal to x.
        - The relative order of nodes in each partition is preserved.

        Approach:
        - Use two dummy heads to build two separate lists:
            - One for nodes less than x.
            - One for nodes greater than or equal to x.
        - Traverse the list once, appending nodes to either partition.
        - Connect the end of the <x list to the head of the ≥x list.
        - Return the merged list starting from dummy1.next.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(1), using only pointers.
        """

        # Dummy heads for the two partitions.
        dummy1 = ListNode(0)
        dummy2 = ListNode(0)

        # Tails to track the end of each list.
        tail1 = dummy1
        tail2 = dummy2

        # Traverse the original list.
        while head:
            if head.val < x:
                tail1.next = head  # Append to the <x list.
                tail1 = tail1.next
            else:
                tail2.next = head  # Append to the ≥x list.
                tail2 = tail2.next
            head = head.next

        # Terminate the ≥x list properly.
        tail2.next = None

        # Connect the two lists.
        tail1.next = dummy2.next

        return dummy1.next

