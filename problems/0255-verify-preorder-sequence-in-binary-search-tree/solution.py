class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        """
        Problem: 0255 - Verify Preorder Sequence in Binary Search Tree
        
        Use a stack to track the path from root to current node. When we
        encounter a value greater than stack top, we're moving to the right
        subtree. Pop all smaller values and update the lower bound to ensure
        BST property is maintained.
        
        Time complexity: O(n) where n is the length of preorder.
        Space complexity: O(n) for the stack.
        """
        stack = []
        lower_bound = float('-inf')
        
        for val in preorder:
            # BST property violated: right subtree value < parent.
            if val < lower_bound:
                return False
            
            # Pop all nodes that are less than current value.
            # We're moving to the right subtree of some ancestor.
            while stack and stack[-1] < val:
                lower_bound = stack.pop()
            
            # Push current value to stack.
            stack.append(val)
        
        return True
