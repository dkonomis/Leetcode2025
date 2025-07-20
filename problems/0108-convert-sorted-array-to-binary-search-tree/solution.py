# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        """
        Problem: 0108 - Convert Sorted Array to Binary Search Tree
        
        Convert a sorted array to a height-balanced BST.
        
        Approach:
        1. Use divide and conquer with middle element as root.
        2. Recursively build left subtree from left half.
        3. Recursively build right subtree from right half.
        
        Time complexity: O(n) where n is number of elements.
        Space complexity: O(log n) for recursion stack.
        """
        def build(left: int, right: int) -> Optional[TreeNode]:
            # Base case: no elements to process.
            if left > right:
                return None
            
            # Choose middle element as root for balance.
            mid = (left + right) // 2
            root = TreeNode(nums[mid])
            
            # Build left subtree from left half.
            root.left = build(left, mid - 1)
            # Build right subtree from right half.
            root.right = build(mid + 1, right)
            
            return root
        
        return build(0, len(nums) - 1)
