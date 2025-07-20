# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        """
        Problem: 0106 - Construct Binary Tree from Inorder and Postorder Traversal
        
        Given inorder and postorder traversals, construct the binary tree.
        
        Key insight: In postorder, the last element is always the root.
        In inorder, elements to the left of root are left subtree, 
        elements to the right are right subtree.
        
        Approach:
        1. Use a hashmap to quickly find root position in inorder
        2. Recursively build right and left subtrees (reverse order!)
        3. Track postorder index from the back to get current root
        
        Time complexity: O(n) where n is number of nodes
        Space complexity: O(n) for hashmap and recursion stack
        """
        if not inorder or not postorder:
            return None
        
        # Create hashmap for O(1) lookup of indices in inorder.
        inorder_map = {val: i for i, val in enumerate(inorder)}
        self.postorder_idx = len(postorder) - 1
        
        def build(left: int, right: int) -> Optional[TreeNode]:
            # Base case: no elements to process.
            if left > right:
                return None
            
            # Current root is the next element from back of postorder.
            root_val = postorder[self.postorder_idx]
            root = TreeNode(root_val)
            self.postorder_idx -= 1
            
            # Find root position in inorder to split left/right subtrees.
            root_idx = inorder_map[root_val]
            
            # Build right subtree first (postorder: left, right, root).
            root.right = build(root_idx + 1, right)
            # Build left subtree.
            root.left = build(left, root_idx - 1)
            
            return root
        
        return build(0, len(inorder) - 1)
