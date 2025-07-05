from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Problem 0021 – Merge Two Sorted Lists.

        Given the heads of two sorted linked lists `list1` and `list2`,
        merge the two lists into one sorted list by splicing together their nodes.

        Return the head of the merged linked list.

        Approach:
        Use a dummy node as a placeholder for the result list head.
        Traverse both input lists simultaneously, and at each step, attach the smaller
        of the two current nodes to the result list.
        Advance the pointer in the list from which the node was taken.
        After one list is exhausted, append the rest of the other list.

        Time Complexity  : O(m + n), where m and n are the lengths of the input lists.
        Space Complexity : O(1), excluding the output list which is constructed in-place.
        """

        dummy = ListNode()
        current = dummy

        while list1 and list2:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        current.next = list1 if list1 else list2

        return dummy.next

