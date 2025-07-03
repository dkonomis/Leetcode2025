from typing import Optional

class ListNode:
    def __init__(self, val: int = 0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Problem: 0002 - Add Two Numbers.

        Given two non-empty linked lists representing two non-negative integers
        in reverse order, add them and return the sum as a new linked list.

        Approach:
        - Use a dummy node to simplify list construction.
        - Traverse both lists simultaneously.
        - Add corresponding digits and carry.
        - Append new nodes to the result list.
        - Return dummy.next (skipping the dummy head).

        Time Complexity: O(max(n, m)), where n and m are lengths of l1 and l2.
        Space Complexity: O(max(n, m)), for the output list.
        """

        dummy = ListNode()         # Dummy node simplifies edge-case handling.
        current = dummy            # Pointer to build the resulting list.
        carry = 0                  # Carry for digits sum.

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0  # Value from l1 or 0.
            val2 = l2.val if l2 else 0  # Value from l2 or 0.

            total = val1 + val2 + carry
            carry = total // 10
            digit = total % 10

            current.next = ListNode(digit)  # Append new digit node.
            current = current.next          # Move to the new end.

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next  # Skip dummy node and return actual head.
