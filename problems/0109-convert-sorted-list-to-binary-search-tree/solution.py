# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.current = None
    
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        """
        Problem: 0109 - Convert Sorted List to Binary Search Tree
        
        Convert a sorted linked list to a height-balanced BST.
        
        Approach:
        1. Count total nodes to determine tree structure.
        2. Use inorder simulation - build left subtree, process current node, build right subtree.
        3. Advance list pointer as we consume nodes in inorder fashion.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(log n) for recursion stack.
        """
        if not head:
            return None
        
        # Count total nodes in the list.
        current = head
        size = 0
        while current:
            size += 1
            current = current.next
        
        # Initialize the current pointer.
        self.current = head
        
        def build_tree(start: int, end: int) -> Optional[TreeNode]:
            # Base case: no nodes to process.
            if start > end:
                return None
            
            # Calculate middle position.
            mid = (start + end) // 2
            
            # Build left subtree first (inorder: left, root, right).
            left_child = build_tree(start, mid - 1)
            
            # Process current node (this is the "root" step in inorder).
            root = TreeNode(self.current.val)
            self.current = self.current.next
            
            # Build right subtree.
            right_child = build_tree(mid + 1, end)
            
            # Connect children.
            root.left = left_child
            root.right = right_child
            
            return root
        
        return build_tree(0, size - 1)
