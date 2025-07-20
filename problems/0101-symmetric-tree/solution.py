# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        """
        Problem: 0101 - Symmetric Tree
        
        Check if a binary tree is symmetric around its center using
        an iterative approach with a queue. For symmetry, we compare
        nodes in pairs: left subtree's left with right subtree's right,
        and left subtree's right with right subtree's left.
        
        Approach: Use a queue to store pairs of nodes that should be
        mirrors of each other. Process pairs level by level.
        
        Time complexity: O(n) - visit each node once.
        Space complexity: O(w) - queue size equals maximum tree width.
        """
        if not root:
            return True
        
        # Queue stores pairs of nodes that should be mirrors.
        queue = collections.deque([(root.left, root.right)])
        
        while queue:
            left, right = queue.popleft()
            
            # Both nodes are None - continue checking other pairs.
            if not left and not right:
                continue
            
            # One node is None, the other isn't - not symmetric.
            if not left or not right:
                return False
            
            # Values don't match - not symmetric.
            if left.val != right.val:
                return False
            
            # Add mirror pairs to queue for next iteration.
            queue.append((left.left, right.right))
            queue.append((left.right, right.left))
        
        return True
