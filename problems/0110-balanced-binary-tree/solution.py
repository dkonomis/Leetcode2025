# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        """
        Problem: 0110 - Balanced Binary Tree
        
        Determine if a binary tree is height-balanced.
        
        Approach:
        1. Use helper function that returns height and balance status simultaneously.
        2. For each node, check if left and right subtrees are balanced.
        3. Check if current node satisfies balance condition (height difference <= 1).
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for recursion stack.
        """
        def check_balance(node: Optional[TreeNode]) -> tuple[int, bool]:
            # Base case: empty node is balanced with height 0.
            if not node:
                return 0, True
            
            # Check left subtree.
            left_height, left_balanced = check_balance(node.left)
            if not left_balanced:
                return -1, False
            
            # Check right subtree.
            right_height, right_balanced = check_balance(node.right)
            if not right_balanced:
                return -1, False
            
            # Check if current node is balanced.
            height_diff = abs(left_height - right_height)
            is_balanced = height_diff <= 1
            current_height = max(left_height, right_height) + 1
            
            return current_height, is_balanced
        
        _, is_balanced = check_balance(root)
        return is_balanced
