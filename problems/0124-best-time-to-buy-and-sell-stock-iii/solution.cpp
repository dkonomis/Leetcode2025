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
private:
    int max_sum;

public:
    int maxPathSum(TreeNode* root) {
        /*
        Problem: 0124 - Binary Tree Maximum Path Sum
        
        Find the maximum path sum in a binary tree.
        
        Approach:
        1. Use post-order traversal to process children before parent.
        2. For each node, calculate max path sum that goes through this node.
        3. Return max path sum that can be extended upward to parent.
        4. Track global maximum across all nodes.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for recursion stack.
        */
        
        max_sum = INT_MIN;
        maxPathHelper(root);
        return max_sum;
    }
    
private:
    int maxPathHelper(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        // Get maximum path sums from left and right subtrees.
        // Use max(0, ...) to ignore negative paths.
        int left_max = max(0, maxPathHelper(node->left));
        int right_max = max(0, maxPathHelper(node->right));
        
        // Calculate maximum path sum that goes through current node.
        int current_max = node->val + left_max + right_max;
        
        // Update global maximum.
        max_sum = max(max_sum, current_max);
        
        // Return maximum path sum that can be extended upward.
        return node->val + max(left_max, right_max);
    }
};
