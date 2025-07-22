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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        /**
         * Problem: 0156 - Binary Tree Upside Down
         * 
         * Flip binary tree where left child becomes new root,
         * original root becomes right child, and original right becomes left child.
         * 
         * Approach:
         * Iterative solution traversing down the left spine.
         * At each node, save pointers and rewire:
         * - Left child becomes parent
         * - Current node becomes right child
         * - Previous right sibling becomes left child
         * 
         * Time complexity: O(h) where h is height.
         * Space complexity: O(1).
         */
        
        if (!root || !root->left) {
            return root;
        }
        
        // Initialize pointers.
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* prev_right = nullptr;
        
        // Traverse down the left spine.
        while (curr) {
            // Save next node to process.
            TreeNode* next_node = curr->left;
            
            // Save current right child.
            TreeNode* curr_right = curr->right;
            
            // Rewire current node.
            curr->left = prev_right;
            curr->right = prev;
            
            // Move pointers for next iteration.
            prev = curr;
            prev_right = curr_right;
            curr = next_node;
        }
        
        // Prev is now the new root (leftmost node).
        return prev;
    }
};
