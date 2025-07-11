class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Problem: 0099 - Recover Binary Search Tree

        Two nodes in a binary search tree are swapped by mistake.
        Recover the tree without changing its structure.

        Approach:
        - Use iterative inorder traversal to visit nodes in sorted order.
        - Track previous node to detect the two nodes that are out of order.
        - The first violation gives us the first wrong node.
        - The second violation (if any) gives us the second wrong node.
        - Swap their values to fix the tree.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(h), where h is the height of the tree.
        """
        stack = []
        current = root
        prev = None
        first = second = None

        # Perform inorder traversal using stack.
        while stack or current:
            # Traverse left subtree.
            while current:
                stack.append(current)
                current = current.left

            # Visit current node.
            current = stack.pop()

            # Check for violation of BST property.
            if prev and current.val < prev.val:
                # First violation: record 'first' and 'second'.
                if not first:
                    first = prev
                    second = current
                else:
                    # Second violation: update 'second' only.
                    second = current

            # Update previous node.
            prev = current

            # Traverse right subtree.
            current = current.right

        # Swap the values of the two nodes to recover the tree.
        if first and second:
            first.val, second.val = second.val, first.val

