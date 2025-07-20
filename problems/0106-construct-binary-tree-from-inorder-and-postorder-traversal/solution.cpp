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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
        Problem: 0106 - Construct Binary Tree from Inorder and Postorder Traversal
        
        Given inorder and postorder traversals, construct the binary tree.
        
        Key insight: In postorder, the last element is always the root.
        In inorder, elements to the left of root are left subtree, 
        elements to the right are right subtree.
        
        Approach:
        1. Use a hashmap to quickly find root position in inorder
        2. Recursively build right and left subtrees (reverse order!)
        3. Track postorder index from the back to get current root
        
        Time complexity: O(n) where n is number of nodes
        Space complexity: O(n) for hashmap and recursion stack
        */
        
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        
        // Create hashmap for O(1) lookup of indices in inorder.
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        int postorder_idx = postorder.size() - 1;
        
        function<TreeNode*(int, int)> build = [&](int left, int right) -> TreeNode* {
            // Base case: no elements to process.
            if (left > right) {
                return nullptr;
            }
            
            // Current root is the next element from back of postorder.
            int root_val = postorder[postorder_idx];
            TreeNode* root = new TreeNode(root_val);
            postorder_idx--;
            
            // Find root position in inorder to split left/right subtrees.
            int root_idx = inorder_map[root_val];
            
            // Build right subtree first (postorder: left, right, root).
            root->right = build(root_idx + 1, right);
            // Build left subtree.
            root->left = build(left, root_idx - 1);
            
            return root;
        };
        
        return build(0, inorder.size() - 1);
    }
};
