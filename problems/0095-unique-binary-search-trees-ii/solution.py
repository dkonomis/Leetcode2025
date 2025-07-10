class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        """
        Problem: 0095 - Unique Binary Search Trees II

        Given an integer n, return all structurally unique BSTs (binary search trees)
        that store values 1 to n.

        Approach:
        - Use recursion with manual memoization to avoid redundant subtree construction.
        - For each (start, end) interval, store already computed trees in a memo table.
        - For each root value i in [start, end]:
            - Recursively build all left subtrees in [start, i - 1]
            - Recursively build all right subtrees in [i + 1, end]
            - Combine each left and right subtree with root i
        - Return all valid BSTs rooted in this interval.

        Time complexity: O(C_n), where C_n is the nth Catalan number ≈ O(4^n / n^1.5)
        Space complexity: O(C_n) for result trees, O(n^2) for memo table, O(n) stack depth
        """
        if n == 0:
            return []

        memo = {}  # Key: (start, end) → Value: list of TreeNode roots

        def build(start: int, end: int) -> List[Optional[TreeNode]]:
            # Return memoized result if already computed.
            if (start, end) in memo:
                return memo[(start, end)]

            # Base case: empty subtree.
            if start > end:
                return [None]

            all_trees = []

            # Try every number i in range [start, end] as root.
            for i in range(start, end + 1):
                # Recursively build all left subtrees from [start, i-1].
                left_subtrees = build(start, i - 1)

                # Recursively build all right subtrees from [i+1, end].
                right_subtrees = build(i + 1, end)

                # Combine each left tree and right tree with root i.
                for left in left_subtrees:
                    for right in right_subtrees:
                        root = TreeNode(i)
                        root.left = left
                        root.right = right
                        all_trees.append(root)

            # Memoize result for current (start, end).
            memo[(start, end)] = all_trees
            return all_trees

        return build(1, n)

