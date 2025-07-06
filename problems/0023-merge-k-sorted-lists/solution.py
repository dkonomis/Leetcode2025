from typing import List, Optional
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    """
    0023. Merge k Sorted Lists

    Problem:
    You are given an array of k linked-lists, each sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    Approach:
    We use a min-heap to always extract the smallest head node among the k lists.
    Each heap entry is a tuple (node value, list index, node). We include the list
    index to avoid comparison errors when node values are equal.

    Time Complexity: O(N log k), where N is the total number of nodes.
    Space Complexity: O(k) for the heap.
    """

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Initialize a min-heap to store the first node of each list.
        min_heap = []

        # Push the head of each non-empty list into the heap.
        for idx, node in enumerate(lists):
            if node:
                heapq.heappush(min_heap, (node.val, idx, node))  # Push value, index, node.

        # Dummy head to build the result list.
        dummy = ListNode(0)
        current = dummy

        # While the heap is not empty, extract the smallest node.
        while min_heap:
            val, idx, node = heapq.heappop(min_heap)  # Pop the smallest node.
            current.next = node  # Append the node to the result.
            current = current.next  # Advance the pointer.

            if node.next:
                heapq.heappush(min_heap, (node.next.val, idx, node.next))  # Push next node in same list.

        return dummy.next  # Return the head of the merged list.

