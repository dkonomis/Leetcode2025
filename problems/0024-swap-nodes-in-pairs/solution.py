from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    """
    0024. Swap Nodes in Pairs

    Problem:
    Given a linked list, swap every two adjacent nodes and return its head.
    You must solve the problem without modifying node values, only pointers.

    Approach:
    Use a dummy node before the head to simplify edge cases.
    Iterate in pairs: at each step, swap two adjacent nodes by reassigning pointers.
    After the swap, move the pointer forward by two nodes.

    Time Complexity: O(n), where n is the number of nodes.
    Space Complexity: O(1), since we use only constant extra space.
    """

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node pointing to the head.
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        # Traverse the list in pairs.
        while prev.next and prev.next.next:
            first = prev.next  # First node in the pair.
            second = first.next  # Second node in the pair.

            # Perform the swap by changing pointers.
            prev.next = second
            first.next = second.next
            second.next = first

            # Move the pointer forward for the next pair.
            prev = first

        return dummy.next  # Return the new head.

