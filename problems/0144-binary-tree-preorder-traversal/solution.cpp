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
    vector<int> preorderTraversal(TreeNode* root) {
        /**
         * Problem: 0144 - Binary Tree Preorder Traversal
         * 
         * Return the preorder traversal of a binary tree's nodes' values.
         * Preorder: root -> left -> right
         * 
         * Approach:
         * Use a stack to simulate the recursive call stack. Push root first,
         * then for each node: process it, push right child, then push left child.
         * We push right before left because stack is LIFO.
         * 
         * Time complexity: O(n).
         * Space complexity: O(h) where h is the height of the tree.
         */
        
        vector<int> res;
        if (!root) {
            return res;
        }
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        // Process nodes until stack is empty.
        while (!stack.empty()) {
            // Pop and process current node.
            TreeNode* node = stack.top();
            stack.pop();
            res.push_back(node->val);
            
            // Push right child first, then left child.
            // Stack is LIFO, so left will be processed first.
            if (node->right) {
                stack.push(node->right);
            }
            if (node->left) {
                stack.push(node->left);
            }
        }
        
        return res;
    }
};
