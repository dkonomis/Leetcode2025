# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        """
        Problem: 0285 - Inorder Successor in BST
        
        Find the inorder successor of node p in a BST. The successor is the
        node with the smallest value greater than p.val. Uses BST properties
        to find the successor in O(h) time without full traversal.
        
        Approach:
        - If we go left (current > p), current could be successor
        - If we go right (current <= p), successor must be in right subtree
        - Track the last node where we went left as potential successor
        
        Time complexity: O(h) where h is height of the tree.
        Space complexity: O(1) as we only use a few variables.
        """
        res = None
        
        # Traverse the tree using BST properties.
        while root:
            if root.val > p.val:
                # Current node is greater than p, could be successor.
                # Save it and go left to find a smaller successor.
                res = root
                root = root.left
            else:
                # Current node is less than or equal to p.
                # Successor must be in the right subtree.
                root = root.right
        
        return res
