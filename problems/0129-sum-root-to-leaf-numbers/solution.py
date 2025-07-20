# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        """
        Problem: 0129 - Sum Root to Leaf Numbers
        
        Calculate sum of all root-to-leaf numbers in binary tree.
        
        Approach:
        1. Use iterative DFS with explicit stack.
        2. Stack stores (node, current_number) pairs.
        3. Build numbers incrementally as we traverse down.
        4. When reaching a leaf, add complete number to total sum.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for stack.
        """
        if not root:
            return 0
        
        total_sum = 0
        stack = [(root, 0)]
        
        while stack:
            node, current_number = stack.pop()
            
            # Build the current number by appending node's digit.
            current_number = current_number * 10 + node.val
            
            # Check if we've reached a leaf node.
            if not node.left and not node.right:
                total_sum += current_number
            else:
                # Add children to stack with updated number.
                if node.right:
                    stack.append((node.right, current_number))
                if node.left:
                    stack.append((node.left, current_number))
        
        return total_sum
