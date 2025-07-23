# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        """
        Problem: 0199 - Binary Tree Right Side View
        
        Given root of binary tree, return values of nodes visible from right side
        ordered from top to bottom (rightmost node at each level).
        
        Approach: Use BFS to traverse level by level. For each level, add the
        rightmost node's value to result. Process nodes left to right in queue.
        
        Time complexity: O(n).
        Space complexity: O(w) where w is maximum width of tree.
        """
        if not root:
            return []
        
        res = []
        queue = deque([root])
        
        # Process each level of the tree.
        while queue:
            level_size = len(queue)
            
            # Process all nodes in current level.
            for i in range(level_size):
                node = queue.popleft()
                
                # If this is the last node in the level, add it to result.
                if i == level_size - 1:
                    res.append(node.val)
                
                # Add children to queue for next level processing.
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return res
