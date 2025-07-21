# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        """
        Problem: 0144 - Binary Tree Preorder Traversal
        
        Return the preorder traversal of a binary tree's nodes' values.
        Preorder: root -> left -> right
        
        Approach:
        Use a stack to simulate the recursive call stack. Push root first,
        then for each node: process it, push right child, then push left child.
        We push right before left because stack is LIFO.
        
        Time complexity: O(n).
        Space complexity: O(h) where h is the height of the tree.
        """
        if not root:
            return []
        
        res = []
        stack = [root]
        
        # Process nodes until stack is empty.
        while stack:
            # Pop and process current node.
            node = stack.pop()
            res.append(node.val)
            
            # Push right child first, then left child.
            # Stack is LIFO, so left will be processed first.
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        
        return res
