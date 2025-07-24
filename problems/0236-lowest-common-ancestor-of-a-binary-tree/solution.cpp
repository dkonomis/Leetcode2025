/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
         * Problem: 0236 - Lowest Common Ancestor of a Binary Tree
         * 
         * Find LCA using recursive approach.
         * If current node is p or q, return it.
         * Recursively search left and right subtrees.
         * If both sides return non-null, current node is LCA.
         * Otherwise, return the non-null side.
         * 
         * Time complexity: O(n) where n is the number of nodes.
         * Space complexity: O(h) where h is the height of the tree.
         */
        
        // Base case: reached null or found p or q.
        if (!root || root == p || root == q) {
            return root;
        }
        
        // Search for p and q in left and right subtrees.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both sides found something, current node is LCA.
        if (left && right) {
            return root;
        }
        
        // Otherwise, return whichever side found something.
        // If both are null, this returns null.
        return left ? left : right;
    }
};
