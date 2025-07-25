# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def longestConsecutive(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0298 - Binary Tree Longest Consecutive Sequence
        
        Find the longest path where values increase by exactly 1 from parent to child.
        Uses iterative BFS to track the consecutive sequence length at each node.
        
        Approach: Use a queue to store (node, current_consecutive_length) pairs.
        When visiting a child, if its value equals parent.val + 1, increment the length;
        otherwise, reset to 1. Track the maximum length seen.
        
        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(w), where w is the maximum width of the tree.
        """
        if not root:
            return 0
        
        res = 0
        # Queue stores tuples of (node, consecutive_length_ending_at_node).
        queue = deque([(root, 1)])
        
        while queue:
            node, length = queue.popleft()
            # Update maximum consecutive length.
            res = max(res, length)
            
            # Process left child.
            if node.left:
                if node.left.val == node.val + 1:
                    # Continue the consecutive sequence.
                    queue.append((node.left, length + 1))
                else:
                    # Start a new sequence.
                    queue.append((node.left, 1))
            
            # Process right child.
            if node.right:
                if node.right.val == node.val + 1:
                    # Continue the consecutive sequence.
                    queue.append((node.right, length + 1))
                else:
                    # Start a new sequence.
                    queue.append((node.right, 1))
        
        return res
