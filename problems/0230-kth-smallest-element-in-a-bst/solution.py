# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        Problem: 0230 - Kth Smallest Element in a BST
        
        Find kth smallest element using iterative inorder traversal.
        Inorder traversal of BST gives nodes in ascending order.
        Stop traversal once we've seen k nodes.
        
        Time complexity: O(k) in best case, O(n) in worst case.
        Space complexity: O(h) where h is the height of the tree.
        """
        stack = []
        current = root
        count = 0
        
        # Iterative inorder traversal.
        while stack or current:
            # Go to the leftmost node.
            while current:
                stack.append(current)
                current = current.left
            
            # Process current node.
            current = stack.pop()
            count += 1
            
            # Check if we found the kth smallest.
            if count == k:
                return current.val
            
            # Move to right subtree.
            current = current.right
        
        # Should never reach here for valid input.
        return -1
