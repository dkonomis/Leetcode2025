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
    int kthSmallest(TreeNode* root, int k) {
        /*
         * Problem: 0230 - Kth Smallest Element in a BST
         * 
         * Find kth smallest element using iterative inorder traversal.
         * Inorder traversal of BST gives nodes in ascending order.
         * Stop traversal once we've seen k nodes.
         * 
         * Time complexity: O(k) in best case, O(n) in worst case.
         * Space complexity: O(h) where h is the height of the tree.
         */
        
        stack<TreeNode*> stk;
        TreeNode* current = root;
        int count = 0;
        
        // Iterative inorder traversal.
        while (!stk.empty() || current) {
            // Go to the leftmost node.
            while (current) {
                stk.push(current);
                current = current->left;
            }
            
            // Process current node.
            current = stk.top();
            stk.pop();
            count++;
            
            // Check if we found the kth smallest.
            if (count == k) {
                return current->val;
            }
            
            // Move to right subtree.
            current = current->right;
        }
        
        // Should never reach here for valid input.
        return -1;
    }
};
