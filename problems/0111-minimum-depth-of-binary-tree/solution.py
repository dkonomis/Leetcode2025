# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0111 - Minimum Depth of Binary Tree
        
        Find the minimum depth to the nearest leaf node.
        
        Approach:
        1. Use BFS (level-order traversal) to explore nodes level by level.
        2. Return depth as soon as we encounter the first leaf node.
        3. BFS guarantees we find the minimum depth first.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(w) where w is maximum width of tree.
        """
        if not root:
            return 0
        
        queue = [(root, 1)]
        
        while queue:
            node, depth = queue.pop(0)
            
            # Check if current node is a leaf.
            if not node.left and not node.right:
                return depth
            
            # Add children to queue with incremented depth.
            if node.left:
                queue.append((node.left, depth + 1))
            if node.right:
                queue.append((node.right, depth + 1))
        
        return 0
