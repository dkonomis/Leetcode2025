# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.max_sum = float('-inf')
    
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0124 - Binary Tree Maximum Path Sum
        
        Find the maximum path sum in a binary tree.
        
        Approach:
        1. Use post-order traversal to process children before parent.
        2. For each node, calculate max path sum that goes through this node.
        3. Return max path sum that can be extended upward to parent.
        4. Track global maximum across all nodes.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for recursion stack.
        """
        def max_path_helper(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            # Get maximum path sums from left and right subtrees.
            # Use max(0, ...) to ignore negative paths.
            left_max = max(0, max_path_helper(node.left))
            right_max = max(0, max_path_helper(node.right))
            
            # Calculate maximum path sum that goes through current node.
            current_max = node.val + left_max + right_max
            
            # Update global maximum.
            self.max_sum = max(self.max_sum, current_max)
            
            # Return maximum path sum that can be extended upward.
            return node.val + max(left_max, right_max)
        
        max_path_helper(root)
        return self.max_sum
