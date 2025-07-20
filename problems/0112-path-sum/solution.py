# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        """
        Problem: 0112 - Path Sum
        
        Check if there exists a root-to-leaf path with given target sum.
        
        Approach:
        1. Use iterative DFS with a stack to traverse all root-to-leaf paths.
        2. Store (node, remaining_sum) pairs in the stack.
        3. At leaf nodes, check if remaining sum equals node value.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for stack.
        """
        if not root:
            return False
        
        stack = [(root, targetSum)]
        
        while stack:
            node, remaining = stack.pop()
            
            # Check if we've reached a leaf with the exact remaining sum.
            if not node.left and not node.right:
                if node.val == remaining:
                    return True
                continue
            
            # Add children to stack with reduced remaining sum.
            if node.left:
                stack.append((node.left, remaining - node.val))
            if node.right:
                stack.append((node.right, remaining - node.val))
        
        return False
