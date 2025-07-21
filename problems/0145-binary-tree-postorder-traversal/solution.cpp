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
    vector<int> postorderTraversal(TreeNode* root) {
        /**
         * Problem: 0145 - Binary Tree Postorder Traversal
         * 
         * Return the postorder traversal of a binary tree's nodes' values.
         * Postorder: left -> right -> root
         * 
         * Approach:
         * Use two stacks. First stack processes nodes in root->right->left order.
         * Second stack reverses this to get left->right->root (postorder).
         * Stack1 does a modified preorder, Stack2 collects for reversal.
         * 
         * Time complexity: O(n).
         * Space complexity: O(n) for the two stacks.
         */
        
        vector<int> res;
        if (!root) {
            return res;
        }
        
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        
        stack1.push(root);
        
        // First stack: process nodes in root -> right -> left order.
        while (!stack1.empty()) {
            TreeNode* node = stack1.top();
            stack1.pop();
            stack2.push(node);
            
            // Push left first, then right (opposite of preorder).
            // This ensures we visit in root -> right -> left order.
            if (node->left) {
                stack1.push(node->left);
            }
            if (node->right) {
                stack1.push(node->right);
            }
        }
        
        // Second stack now has nodes in reverse postorder.
        // Pop all to get postorder: left -> right -> root.
        while (!stack2.empty()) {
            res.push_back(stack2.top()->val);
            stack2.pop();
        }
        
        return res;
    }
};
