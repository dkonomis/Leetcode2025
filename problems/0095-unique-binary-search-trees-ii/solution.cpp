class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        /*
        Problem: 0095 - Unique Binary Search Trees II

        Given an integer n, return all structurally unique BSTs (binary search trees)
        that store values 1 to n.

        Approach:
        - Use recursion with manual memoization to avoid recomputing subtrees.
        - For each interval (start, end), cache the result list of BST roots.
        - For every possible root value i in [start, end]:
            - Recursively build all left subtrees from [start, i - 1].
            - Recursively build all right subtrees from [i + 1, end].
            - Combine each left and right with a new root node i.
        - Return the cached result if already computed.

        Time complexity: O(C_n), where C_n is the nth Catalan number ≈ O(4^n / n^1.5)
        Space complexity: O(C_n) for result trees, O(n^2) memoization, O(n) recursion stack
        */
        if (n == 0) {
            return {};
        }

        return build(1, n);
    }

private:
    // Memoization table: key = (start, end), value = list of trees for that interval.
    map<pair<int, int>, vector<TreeNode*>> memo;

    // Recursively build all unique BSTs for values in the range [start, end].
    vector<TreeNode*> build(int start, int end) {
        // Return memoized result if available.
        if (memo.count({start, end})) {
            return memo[{start, end}];
        }

        // Base case: empty subtree → return vector with one nullptr.
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> all_trees;

        // Try each number in the range as the root.
        for (int i = start; i <= end; ++i) {
            // Recursively generate all left subtrees.
            vector<TreeNode*> left_subtrees = build(start, i - 1);

            // Recursively generate all right subtrees.
            vector<TreeNode*> right_subtrees = build(i + 1, end);

            // Combine left and right with root i.
            for (TreeNode* left : left_subtrees) {
                for (TreeNode* right : right_subtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    all_trees.push_back(root);
                }
            }
        }

        // Cache and return the result for (start, end).
        memo[{start, end}] = all_trees;
        return all_trees;
    }
};

