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
    TreeNode* invertTree(TreeNode* root) {
        /**
         * Problem: 0226 - Invert Binary Tree
         * 
         * Invert binary tree iteratively using a queue (BFS approach).
         * For each node, swap its left and right children.
         * Process all nodes level by level using a queue.
         * 
         * Time complexity: O(n) where n is the number of nodes.
         * Space complexity: O(w) where w is the maximum width of the tree.
         */
        
        if (!root) {
            return nullptr;
        }
        
        // Use a queue for BFS traversal.
        queue<TreeNode*> q;
        q.push(root);
        
        // Process nodes level by level.
        while (!q.empty()) {
            // Get the next node to process.
            TreeNode* node = q.front();
            q.pop();
            
            // Swap left and right children.
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            
            // Add children to queue for processing.
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        
        return root;
    }
};
