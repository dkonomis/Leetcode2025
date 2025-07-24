# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        Problem: 0235 - Lowest Common Ancestor of a Binary Search Tree
        
        Find LCA using BST property iteratively.
        If both nodes are smaller than current, go left.
        If both nodes are larger than current, go right.
        Otherwise, current node is the LCA.
        
        Time complexity: O(h) where h is the height of the tree.
        Space complexity: O(1).
        """
        current = root
        
        # Traverse the tree until we find the LCA.
        while current:
            # Both nodes are in the left subtree.
            if p.val < current.val and q.val < current.val:
                current = current.left
            # Both nodes are in the right subtree.
            elif p.val > current.val and q.val > current.val:
                current = current.right
            else:
                # Found the split point or one node equals current.
                # This is the LCA.
                return current
        
        # Should never reach here given the constraints.
        return None
