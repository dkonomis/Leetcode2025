# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Problem: 0102 - Binary Tree Level Order Traversal
        
        Return level order traversal of a binary tree's node values,
        where each level is processed from left to right. Use BFS
        with a queue to process nodes level by level.
        
        Approach: Use a queue to store nodes at current level. For each
        level, process all nodes currently in queue, collect their values,
        and add their children for the next level.
        
        Time complexity: O(n) - visit each node exactly once.
        Space complexity: O(w) - queue stores at most one complete level, where w is maximum tree width.
        """
        if not root:
            return []
        
        res = []
        queue = collections.deque([root])
        
        while queue:
            level_size = len(queue)
            current_level = []
            
            # Process all nodes at current level.
            for _ in range(level_size):
                # Get next node from current level.
                node = queue.popleft()
                # Add value to current level result.
                current_level.append(node.val)
                
                # Add children for next level processing.
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # Add completed level to final result.
            res.append(current_level)
        
        return res
