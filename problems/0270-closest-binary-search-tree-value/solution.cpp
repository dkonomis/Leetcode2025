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
    int closestValue(TreeNode* root, double target) {
        /**
         * Problem: 0270 - Closest Binary Search Tree Value
         * 
         * Find the node value in BST closest to target. If tie, return smaller value.
         * 
         * Approach: Use BST property to guide search. At each node, update closest value
         * if current node is closer to target. Then move left if target < node value,
         * else move right. This gives O(h) time where h is height.
         * 
         * Time complexity: O(h) where h is the height of the tree.
         * Space complexity: O(1) using iterative approach.
         */
        
        int closest = root->val;
        
        while (root) {
            // Update closest if current node is closer to target.
            if (abs(root->val - target) < abs(closest - target)) {
                closest = root->val;
            }
            // Handle tie: choose smaller value.
            else if (abs(root->val - target) == abs(closest - target)) {
                closest = min(closest, root->val);
            }
            
            // Use BST property to search efficiently.
            if (target < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        return closest;
    }
};
