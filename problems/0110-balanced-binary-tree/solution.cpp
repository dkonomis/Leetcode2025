/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        /*
        Problem: 0110 - Balanced Binary Tree
        
        Determine if a binary tree is height-balanced.
        
        Approach:
        1. Use helper function that returns height and balance status simultaneously.
        2. For each node, check if left and right subtrees are balanced.
        3. Check if current node satisfies balance condition (height difference <= 1).
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for recursion stack.
        */
        
        function<pair<int, bool>(TreeNode*)> check_balance = [&](TreeNode* node) -> pair<int, bool> {
            // Base case: empty node is balanced with height 0.
            if (!node) {
                return {0, true};
            }
            
            // Check left subtree.
            auto [left_height, left_balanced] = check_balance(node->left);
            if (!left_balanced) {
                return {-1, false};
            }
            
            // Check right subtree.
            auto [right_height, right_balanced] = check_balance(node->right);
            if (!right_balanced) {
                return {-1, false};
            }
            
            // Check if current node is balanced.
            int height_diff = abs(left_height - right_height);
            bool is_balanced = height_diff <= 1;
            int current_height = max(left_height, right_height) + 1;
            
            return {current_height, is_balanced};
        };
        
        auto [_, is_balanced] = check_balance(root);
        return is_balanced;
    }
};
