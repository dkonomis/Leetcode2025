class Solution {
public:
    int numTrees(int n) {
        /*
        Problem: 0096 - Unique Binary Search Trees

        Given an integer n, return the number of structurally unique BSTs
        that store values 1 to n.

        Approach:
        - Use bottom-up dynamic programming based on the Catalan number recurrence.
        - Let dp[i] represent the number of unique BSTs that can be formed with i nodes.
        - For each node count i, iterate all possible root positions j (1 to i),
          and compute:
              dp[i] += dp[j - 1] * dp[i - j]
          where:
              - dp[j - 1] is the number of left subtrees
              - dp[i - j] is the number of right subtrees

        Time complexity: O(n^2)
        Space complexity: O(n)
        */
        vector<int> dp(n + 1, 0);
        dp[0] = 1;  // Base case: one empty tree.

        // Compute number of unique BSTs for each size from 1 to n.
        for (int nodes = 1; nodes <= n; ++nodes) {
            // Try each value as the root of the tree.
            for (int root = 1; root <= nodes; ++root) {
                int left = dp[root - 1];       // Number of BSTs in left subtree.
                int right = dp[nodes - root];  // Number of BSTs in right subtree.
                dp[nodes] += left * right;
            }
        }

        return dp[n];
    }
};

