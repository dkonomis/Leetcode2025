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
    int countNodes(TreeNode* root) {
        /**
         * Problem: 0222 - Count Complete Tree Nodes
         * 
         * Count nodes in a complete binary tree in less than O(n) time.
         * Use the property that in a complete tree, all levels are full except possibly the last.
         * If left and right heights are equal, the tree is perfect and has 2^h - 1 nodes.
         * Otherwise, recursively count nodes in left and right subtrees.
         * 
         * Time complexity: O(log^2 n) where n is the number of nodes.
         * Space complexity: O(log n) for the recursion stack.
         */
        
        if (!root) {
            return 0;
        }
        
        // Get the height of leftmost and rightmost paths.
        int left_height = getLeftHeight(root);
        int right_height = getRightHeight(root);
        
        if (left_height == right_height) {
            // Tree is perfect, so it has 2^height - 1 nodes.
            // Use bit shifting for efficiency: 2^h = 1 << h.
            return (1 << left_height) - 1;
        } else {
            // Tree is not perfect, recursively count left and right subtrees.
            // Add 1 for the current root node.
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
    
private:
    int getLeftHeight(TreeNode* node) {
        // Get height by following leftmost path.
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    int getRightHeight(TreeNode* node) {
        // Get height by following rightmost path.
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};
