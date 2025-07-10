class Solution:
    def numTrees(self, n: int) -> int:
        """
        Problem: 0096 - Unique Binary Search Trees

        Given an integer n, return the number of structurally unique BSTs (binary search trees)
        that store values 1 to n.

        Approach:
        - Use bottom-up dynamic programming (Catalan numbers).
        - Let dp[i] represent the number of unique BSTs that can be built with i nodes.
        - For each i in [1, n], compute dp[i] as the sum over all possible roots:
            dp[i] += dp[j - 1] * dp[i - j] for j in 1..i
            (j is the root; dp[j-1] is left subtree count, dp[i-j] is right)

        Time complexity: O(n^2)
        Space complexity: O(n)
        """
        dp = [0] * (n + 1)
        dp[0] = 1  # One empty tree.

        # Build dp[1] to dp[n] using the Catalan recurrence.
        for nodes in range(1, n + 1):
            # Try every number as root.
            for root in range(1, nodes + 1):
                left = dp[root - 1]
                right = dp[nodes - root]
                dp[nodes] += left * right

        return dp[n]

