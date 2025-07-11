class Solution {
public:
    bool isValidBST(TreeNode* root) {
        /*
        Problem: 0098 - Validate Binary Search Tree

        Given the root of a binary tree, determine whether it is a valid binary search tree (BST).
        A valid BST must satisfy:
        - All nodes in the left subtree have values strictly less than the current node.
        - All nodes in the right subtree have values strictly greater than the current node.
        - Both subtrees must also be valid BSTs.

        Approach:
        - Use an explicit stack for iterative traversal.
        - Each stack entry stores: (node, lower bound, upper bound).
        - For each node, check that its value is strictly within (lower, upper).
        - Push left and right children with updated bounds.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(h), where h is the height of the tree.
        */
        if (!root) {
            return true;
        }

        // Stack of tuples: node, lower bound, upper bound.
        stack<tuple<TreeNode*, long, long>> stk;
        stk.push({root, LONG_MIN, LONG_MAX});

        // Iterate while the stack is not empty.
        while (!stk.empty()) {
            TreeNode* node;
            long lower, upper;
            tie(node, lower, upper) = stk.top();
            stk.pop();

            // Check if the current node violates BST property.
            if (node->val <= lower || node->val >= upper) {
                return false;
            }

            // Push right child with updated lower bound.
            if (node->right) {
                stk.push({node->right, node->val, upper});
            }

            // Push left child with updated upper bound.
            if (node->left) {
                stk.push({node->left, lower, node->val});
            }
        }

        return true;
    }
};

