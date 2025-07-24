# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Problem: 0226 - Invert Binary Tree
        
        Invert binary tree iteratively using a queue (BFS approach).
        For each node, swap its left and right children.
        Process all nodes level by level using a queue.
        
        Time complexity: O(n) where n is the number of nodes.
        Space complexity: O(w) where w is the maximum width of the tree.
        """
        if not root:
            return None
        
        # Use a queue for BFS traversal.
        queue = deque([root])
        
        # Process nodes level by level.
        while queue:
            # Get the next node to process.
            node = queue.popleft()
            
            # Swap left and right children.
            node.left, node.right = node.right, node.left
            
            # Add children to queue for processing.
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        return root
