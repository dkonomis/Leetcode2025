# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countUnivalSubtrees(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0250 - Count Univalue Subtrees
        
        Count subtrees where all nodes have the same value.
        Use post-order traversal to check each subtree bottom-up.
        Return tuple: (is_univalue, count) from each subtree.
        
        Time complexity: O(n) where n is the number of nodes.
        Space complexity: O(h) where h is the height of the tree.
        """
        def helper(node: Optional[TreeNode]) -> tuple[bool, int]:
            # Base case: empty tree is univalue with 0 count.
            if not node:
                return (True, 0)
            
            # Check left and right subtrees recursively.
            left_is_uni, left_count = helper(node.left)
            right_is_uni, right_count = helper(node.right)
            
            # Start with count from children.
            count = left_count + right_count
            
            # Check if current subtree is univalue.
            is_uni = True
            
            # Must have univalue children.
            if not left_is_uni or not right_is_uni:
                is_uni = False
            
            # Check if current node matches its children.
            if node.left and node.left.val != node.val:
                is_uni = False
            if node.right and node.right.val != node.val:
                is_uni = False
            
            # If this is a univalue subtree, increment count.
            if is_uni:
                count += 1
            
            # Return whether current subtree is univalue and total count.
            return (is_uni, count)
        
        # Get the total count from the root.
        _, total_count = helper(root)
        return total_count
