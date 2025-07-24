# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        Problem: 0237 - Delete Node in a Linked List
        
        Delete a node without access to the head of the list.
        Copy the next node's value to current node.
        Skip the next node by updating the pointer.
        This effectively "deletes" the current node.
        
        Time complexity: O(1).
        Space complexity: O(1).
        
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # Copy the value of the next node to current node.
        node.val = node.next.val
        
        # Skip the next node by updating the pointer.
        node.next = node.next.next
