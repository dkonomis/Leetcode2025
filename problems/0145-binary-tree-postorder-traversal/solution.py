# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        """
        Problem: 0145 - Binary Tree Postorder Traversal
        
        Return the postorder traversal of a binary tree's nodes' values.
        Postorder: left -> right -> root
        
        Approach:
        Use two stacks. First stack processes nodes in root->right->left order.
        Second stack reverses this to get left->right->root (postorder).
        Stack1 does a modified preorder, Stack2 collects for reversal.
        
        Time complexity: O(n).
        Space complexity: O(n) for the two stacks.
        """
        if not root:
            return []
        
        stack1 = [root]
        stack2 = []
        
        # First stack: process nodes in root -> right -> left order.
        while stack1:
            node = stack1.pop()
            stack2.append(node)
            
            # Push left first, then right (opposite of preorder).
            # This ensures we visit in root -> right -> left order.
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)
        
        # Second stack now has nodes in reverse postorder.
        # Pop all to get postorder: left -> right -> root.
        res = []
        while stack2:
            res.append(stack2.pop().val)
        
        return res
