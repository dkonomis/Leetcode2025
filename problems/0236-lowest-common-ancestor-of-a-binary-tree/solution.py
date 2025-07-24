# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        Problem: 0236 - Lowest Common Ancestor of a Binary Tree
        
        Find LCA using recursive approach.
        If current node is p or q, return it.
        Recursively search left and right subtrees.
        If both sides return non-null, current node is LCA.
        Otherwise, return the non-null side.
        
        Time complexity: O(n) where n is the number of nodes.
        Space complexity: O(h) where h is the height of the tree.
        """
        # Base case: reached null or found p or q.
        if not root or root == p or root == q:
            return root
        
        # Search for p and q in left and right subtrees.
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        
        # If both sides found something, current node is LCA.
        if left and right:
            return root
        
        # Otherwise, return whichever side found something.
        # If both are null, this returns null.
        return left if left else right
