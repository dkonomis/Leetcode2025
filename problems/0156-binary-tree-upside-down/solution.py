# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        Problem: 0156 - Binary Tree Upside Down
        
        Flip binary tree where left child becomes new root,
        original root becomes right child, and original right becomes left child.
        
        Approach:
        Iterative solution traversing down the left spine.
        At each node, save pointers and rewire:
        - Left child becomes parent
        - Current node becomes right child
        - Previous right sibling becomes left child
        
        Time complexity: O(h) where h is height.
        Space complexity: O(1).
        """
        if not root or not root.left:
            return root
        
        # Initialize pointers.
        curr = root
        prev = None
        prev_right = None
        
        # Traverse down the left spine.
        while curr:
            # Save next node to process.
            next_node = curr.left
            
            # Save current right child.
            curr_right = curr.right
            
            # Rewire current node.
            curr.left = prev_right
            curr.right = prev
            
            # Move pointers for next iteration.
            prev = curr
            prev_right = curr_right
            curr = next_node
        
        # Prev is now the new root (leftmost node).
        return prev
