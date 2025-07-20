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
    void flatten(TreeNode* root) {
        /*
        Problem: 0114 - Flatten Binary Tree to Linked List
        
        Flatten binary tree to linked list in preorder traversal order.
        
        Approach (Recursive):
        1. Recursively flatten left and right subtrees.
        2. Save the original right subtree before modifying.
        3. Move left subtree to right, set left to nullptr.
        4. Find the tail of moved left subtree and attach original right.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for recursion stack.
        */
        
        if (!root) {
            return;
        }
        
        // Recursively flatten left and right subtrees.
        flatten(root->left);
        flatten(root->right);
        
        // Save the original right subtree.
        TreeNode* original_right = root->right;
        
        // Move left subtree to right position.
        root->right = root->left;
        root->left = nullptr;
        
        // Find the tail of the moved left subtree.
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        
        // Attach the original right subtree to the tail.
        current->right = original_right;
    }
};
