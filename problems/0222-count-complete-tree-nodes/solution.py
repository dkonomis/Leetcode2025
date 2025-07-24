# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0222 - Count Complete Tree Nodes
        
        Count nodes in a complete binary tree in less than O(n) time.
        Use the property that in a complete tree, all levels are full except possibly the last.
        If left and right heights are equal, the tree is perfect and has 2^h - 1 nodes.
        Otherwise, recursively count nodes in left and right subtrees.
        
        Time complexity: O(log^2 n) where n is the number of nodes.
        Space complexity: O(log n) for the recursion stack.
        """
        if not root:
            return 0
        
        # Get the height of leftmost and rightmost paths.
        left_height = self.get_left_height(root)
        right_height = self.get_right_height(root)
        
        if left_height == right_height:
            # Tree is perfect, so it has 2^height - 1 nodes.
            # Use bit shifting for efficiency: 2^h = 1 << h.
            return (1 << left_height) - 1
        else:
            # Tree is not perfect, recursively count left and right subtrees.
            # Add 1 for the current root node.
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)
    
    def get_left_height(self, node: Optional[TreeNode]) -> int:
        """Get height by following leftmost path."""
        height = 0
        while node:
            height += 1
            node = node.left
        return height
    
    def get_right_height(self, node: Optional[TreeNode]) -> int:
        """Get height by following rightmost path."""
        height = 0
        while node:
            height += 1
            node = node.right
        return height
