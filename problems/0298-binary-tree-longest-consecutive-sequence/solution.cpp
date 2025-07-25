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
    int longestConsecutive(TreeNode* root) {
        /**
         * Problem: 0298 - Binary Tree Longest Consecutive Sequence
         * 
         * Find the longest path where values increase by exactly 1 from parent to child.
         * Uses iterative BFS to track the consecutive sequence length at each node.
         * 
         * Approach: Use a queue to store (node, current_consecutive_length) pairs.
         * When visiting a child, if its value equals parent.val + 1, increment the length;
         * otherwise, reset to 1. Track the maximum length seen.
         * 
         * Time complexity: O(n), where n is the number of nodes.
         * Space complexity: O(w), where w is the maximum width of the tree.
         */
        
        if (!root) return 0;
        
        int res = 0;
        // Queue stores pairs of (node, consecutive_length_ending_at_node).
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [node, length] = q.front();
            q.pop();
            
            // Update maximum consecutive length.
            res = max(res, length);
            
            // Process left child.
            if (node->left) {
                if (node->left->val == node->val + 1) {
                    // Continue the consecutive sequence.
                    q.push({node->left, length + 1});
                } else {
                    // Start a new sequence.
                    q.push({node->left, 1});
                }
            }
            
            // Process right child.
            if (node->right) {
                if (node->right->val == node->val + 1) {
                    // Continue the consecutive sequence.
                    q.push({node->right, length + 1});
                } else {
                    // Start a new sequence.
                    q.push({node->right, 1});
                }
            }
        }
        
        return res;
    }
};
