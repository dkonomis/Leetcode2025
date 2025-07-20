# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Problem: 0107 - Binary Tree Level Order Traversal II
        
        Return the bottom-up level order traversal of binary tree nodes.
        
        Approach:
        1. Use BFS (queue) to traverse level by level.
        2. For each level, process all nodes and collect their values.
        3. Insert each level at beginning for bottom-up order.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(w) where w is maximum width of tree.
        """
        if not root:
            return []
        
        res = []
        queue = [root]
        
        while queue:
            level_size = len(queue)
            level_nodes = []
            
            # Process all nodes at current level.
            for _ in range(level_size):
                node = queue.pop(0)
                level_nodes.append(node.val)
                
                # Add children for next level.
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # Insert at beginning for bottom-up order.
            res.insert(0, level_nodes)
        
        return res
