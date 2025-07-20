# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        """
        Problem: 0113 - Path Sum II
        
        Return all root-to-leaf paths where the sum equals targetSum.
        
        Approach:
        1. Use backtracking to explore all root-to-leaf paths.
        2. Build current path as we traverse down the tree.
        3. When reaching a leaf with correct sum, add path copy to results.
        4. Backtrack by removing current node when returning.
        
        Time complexity: O(n * h) where n is number of nodes and h is height.
        Space complexity: O(h) for recursion stack and path storage.
        """
        if not root:
            return []
        
        res = []
        path = []
        
        def backtrack(node: Optional[TreeNode], remaining: int) -> None:
            # Add current node to path.
            path.append(node.val)
            
            # Check if we've reached a leaf with the exact remaining sum.
            if not node.left and not node.right:
                if node.val == remaining:
                    res.append(path[:])  # Add copy of current path.
            else:
                # Continue exploring children.
                new_remaining = remaining - node.val
                if node.left:
                    backtrack(node.left, new_remaining)
                if node.right:
                    backtrack(node.right, new_remaining)
            
            # Backtrack: remove current node from path.
            path.pop()
        
        backtrack(root, targetSum)
        return res
