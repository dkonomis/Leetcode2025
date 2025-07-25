# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def closestKValues(self, root: Optional[TreeNode], target: float, k: int) -> List[int]:
        """
        Problem: 0272 - Closest Binary Search Tree Value II
        
        Find k values in BST closest to target.
        
        Approach: In-order traversal with sliding window. Maintain k closest values
        seen so far. When window is full, compare new value with furthest value in
        window and keep the closer one.
        
        Time complexity: O(n) where n is number of nodes in the tree.
        Space complexity: O(k) for storing k closest values.
        """
        from collections import deque
        
        # Use deque to maintain k closest values.
        closest = deque()
        
        def inorder(node):
            if not node:
                return
            
            # Process left subtree.
            inorder(node.left)
            
            # Process current node.
            if len(closest) < k:
                # Window not full, just add.
                closest.append(node.val)
            else:
                # Window full, check if current is closer than furthest.
                # In ascending order, furthest from target is either first or last.
                if abs(node.val - target) < abs(closest[0] - target):
                    closest.popleft()
                    closest.append(node.val)
                else:
                    # Current node and all subsequent nodes are further away.
                    return
            
            # Process right subtree.
            inorder(node.right)
        
        inorder(root)
        return list(closest)
