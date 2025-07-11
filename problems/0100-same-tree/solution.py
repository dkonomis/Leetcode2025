class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        """
        Problem: 0100 - Same Tree

        Given two binary trees, determine whether they are the same.
        Two trees are the same if they are structurally identical and all node values are equal.

        Approach:
        - Use an iterative Breadth-First Search (BFS) with a queue.
        - Enqueue pairs of nodes (one from each tree) and compare them.
        - At each step:
            - If both nodes are None: continue.
            - If only one is None or values differ: return False.
            - Otherwise, enqueue left and right children in pairs.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(n) for the queue.
        """
        from collections import deque

        queue = deque([(p, q)])

        # Process all node pairs in the queue.
        while queue:
            node1, node2 = queue.popleft()

            # If both nodes are None, continue to next pair.
            if not node1 and not node2:
                continue

            # If only one is None or values differ, trees are not the same.
            if not node1 or not node2 or node1.val != node2.val:
                return False

            # Enqueue left children.
            queue.append((node1.left, node2.left))

            # Enqueue right children.
            queue.append((node1.right, node2.right))

        return True

