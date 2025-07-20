"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        """
        Problem: 0116 - Populating Next Right Pointers in Each Node
        
        Populate next pointers to point to next right node in perfect binary tree.
        
        Approach:
        1. Use BFS (level-order traversal) to process nodes level by level.
        2. For each level, connect consecutive nodes using next pointers.
        3. Last node in each level has next = None (already set).
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(w) where w is maximum width of tree.
        """
        if not root:
            return root
        
        queue = [root]
        
        while queue:
            level_size = len(queue)
            
            # Process all nodes at current level.
            for i in range(level_size):
                node = queue.pop(0)
                
                # Connect to next node in the same level.
                if i < level_size - 1:
                    node.next = queue[0]
                
                # Add children for next level.
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return root
