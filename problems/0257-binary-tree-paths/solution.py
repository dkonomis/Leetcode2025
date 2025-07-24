# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        """
        Problem: 0257 - Binary Tree Paths
        
        Find all root-to-leaf paths using iterative DFS with a stack.
        Maintain parallel stacks for nodes and their corresponding paths.
        When we pop a leaf node, add its path to results.
        
        Time complexity: O(n) where n is the number of nodes.
        Space complexity: O(n) for the stacks and output.
        """
        if not root:
            return []
        
        res = []
        # Stack of (node, path_to_node) pairs.
        stack = [(root, str(root.val))]
        
        while stack:
            node, path = stack.pop()
            
            # If leaf node, add path to results.
            if not node.left and not node.right:
                res.append(path)
                continue
            
            # Push children with updated paths.
            if node.right:
                stack.append((node.right, path + "->" + str(node.right.val)))
            if node.left:
                stack.append((node.left, path + "->" + str(node.left.val)))
        
        return res
