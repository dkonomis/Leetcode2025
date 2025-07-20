# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Problem: 0103 - Binary Tree Zigzag Level Order Traversal
        
        Return zigzag level order traversal where odd levels go left to right
        and even levels go right to left. Use BFS with a regular queue and
        insert values at front or back of current level based on direction.
        
        Approach: Standard BFS level order traversal, but alternate inserting
        at the beginning vs end of current level list to achieve zigzag effect.
        
        Time complexity: O(n) - visit each node exactly once.
        Space complexity: O(w) - queue stores at most one complete level, where w is maximum tree width.
        """
        if not root:
            return []
        
        res = []
        queue = collections.deque([root])
        left_to_right = True
        
        while queue:
            level_size = len(queue)
            current_level = []
            
            # Process all nodes at current level.
            for _ in range(level_size):
                # Get next node from current level.
                node = queue.popleft()
                
                if left_to_right:
                    # Add value to end of current level.
                    current_level.append(node.val)
                else:
                    # Add value to front of current level.
                    current_level.insert(0, node.val)
                
                # Add children for next level processing.
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # Add completed level to final result.
            res.append(current_level)
            # Flip direction for next level.
            left_to_right = not left_to_right
        
        return res
