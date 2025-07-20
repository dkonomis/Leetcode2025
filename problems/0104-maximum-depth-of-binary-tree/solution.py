# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0104 - Maximum Depth of Binary Tree
        
        Find the maximum depth of a binary tree using iterative DFS with
        a stack. Track each node with its current depth and maintain
        the maximum depth seen so far.
        
        Approach: Use a stack to store (node, depth) pairs. Process each
        node by checking if its depth is the new maximum, then add its
        children with incremented depth to the stack.
        
        Time complexity: O(n) - visit each node exactly once.
        Space complexity: O(h) - stack stores at most h nodes, where h is tree height.
        """
        if not root:
            return 0
        
        stack = [(root, 1)]
        max_depth = 0
        
        while stack:
            # Get next node and its depth from stack.
            node, depth = stack.pop()
            
            # Update maximum depth if current depth is greater.
            max_depth = max(max_depth, depth)
            
            # Add children with incremented depth to stack.
            if node.left:
                stack.append((node.left, depth + 1))
            if node.right:
                stack.append((node.right, depth + 1))
        
        return max_depth
