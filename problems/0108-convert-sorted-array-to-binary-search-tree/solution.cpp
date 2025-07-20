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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /*
        Problem: 0108 - Convert Sorted Array to Binary Search Tree
        
        Convert a sorted array to a height-balanced BST.
        
        Approach:
        1. Use divide and conquer with middle element as root.
        2. Recursively build left subtree from left half.
        3. Recursively build right subtree from right half.
        
        Time complexity: O(n) where n is number of elements.
        Space complexity: O(log n) for recursion stack.
        */
        
        function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
            // Base case: no elements to process.
            if (left > right) {
                return nullptr;
            }
            
            // Choose middle element as root for balance.
            int mid = (left + right) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            
            // Build left subtree from left half.
            root->left = build(left, mid - 1);
            // Build right subtree from right half.
            root->right = build(mid + 1, right);
            
            return root;
        };
        
        return build(0, nums.size() - 1);
    }
};
