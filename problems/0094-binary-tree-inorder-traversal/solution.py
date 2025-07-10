class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        """
        Problem: 0094 - Binary Tree Inorder Traversal

        Given the root of a binary tree, return the inorder traversal of its nodes' values.

        Approach:
        - Use an iterative approach with an explicit stack.
        - Traverse left down the tree, pushing each node onto the stack.
        - When reaching a None, pop the node from the stack, visit it,
          and then move to its right child.
        - Repeat this process until all nodes are visited.

        Time complexity: O(n), where n is the number of nodes in the tree.
        Space complexity: O(h), where h is the height of the tree (stack depth).
        """
        res = []
        stack = []
        current = root

        # Traverse the tree using an explicit stack.
        while current or stack:
            # Go as left as possible, pushing nodes onto the stack.
            while current:
                stack.append(current)
                current = current.left

            # Visit the node on top of the stack.
            current = stack.pop()
            res.append(current.val)

            # Move to the right child.
            current = current.right

        return res

