# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        Problem: 0105 - Construct Binary Tree from Preorder and Inorder Traversal
        
        Construct a binary tree from its preorder and inorder traversals.
        Use the fact that preorder[0] is always the root, and inorder
        splits into left and right subtrees around the root.
        
        Approach: Recursive divide and conquer. Find root in inorder to
        determine left/right subtree sizes, then recursively build
        subtrees with corresponding preorder/inorder slices.
        
        Time complexity: O(n) - each node is visited once with O(1) hashmap lookup.
        Space complexity: O(n) - hashmap storage plus O(h) recursion stack depth.
        """
        if not preorder or not inorder:
            return None
        
        # Create hashmap for O(1) inorder index lookups.
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        self.preorder_idx = 0
        
        def build_subtree(left: int, right: int) -> Optional[TreeNode]:
            if left > right:
                return None
            
            # Get root value from preorder and create node.
            root_val = preorder[self.preorder_idx]
            self.preorder_idx += 1
            root = TreeNode(root_val)
            
            # Find root position in inorder to split subtrees.
            root_idx = inorder_map[root_val]
            
            # Build left subtree first (preorder: root, left, right).
            root.left = build_subtree(left, root_idx - 1)
            # Build right subtree second.
            root.right = build_subtree(root_idx + 1, right)
            
            return root
        
        return build_subtree(0, len(inorder) - 1)
