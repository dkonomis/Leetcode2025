class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        """
        Problem: 0098 - Validate Binary Search Tree

        Given the root of a binary tree, determine whether it is a valid binary search tree (BST).
        A BST is valid if:
        - The left subtree of each node contains only nodes with values < node.val.
        - The right subtree of each node contains only nodes with values > node.val.
        - Both subtrees must also be valid BSTs.

        Approach:
        - Use an explicit stack for iterative DFS traversal.
        - Each stack entry contains: (node, lower bound, upper bound).
        - At each step:
            - Check that node.val is within (lower, upper) exclusive bounds.
            - Push left and right children with updated bounds.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(h), where h is the height of the tree.
        """
        if not root:
            return True

        stack = [(root, float('-inf'), float('inf'))]

        # Iterate over the stack while there are nodes to check.
        while stack:
            node, lower, upper = stack.pop()

            # Check if the node violates BST bounds.
            if not (lower < node.val < upper):
                return False

            # Push right child with updated lower bound.
            if node.right:
                stack.append((node.right, node.val, upper))

            # Push left child with updated upper bound.
            if node.left:
                stack.append((node.left, lower, node.val))

        return True

