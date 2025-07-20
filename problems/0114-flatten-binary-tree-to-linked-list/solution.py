# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Problem: 0114 - Flatten Binary Tree to Linked List
        
        Flatten binary tree to linked list in preorder traversal order.
        
        Approach (Recursive):
        1. Recursively flatten left and right subtrees.
        2. Save the original right subtree before modifying.
        3. Move left subtree to right, set left to None.
        4. Find the tail of moved left subtree and attach original right.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for recursion stack.
        """
        if not root:
            return
        
        # Recursively flatten left and right subtrees.
        self.flatten(root.left)
        self.flatten(root.right)
        
        # Save the original right subtree.
        original_right = root.right
        
        # Move left subtree to right position.
        root.right = root.left
        root.left = None
        
        # Find the tail of the moved left subtree.
        current = root
        while current.right:
            current = current.right
        
        # Attach the original right subtree to the tail.
        current.right = original_right
