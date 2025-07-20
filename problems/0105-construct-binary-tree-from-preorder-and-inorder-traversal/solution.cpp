/*
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        Problem: 0105 - Construct Binary Tree from Preorder and Inorder Traversal
        
        Construct a binary tree from its preorder and inorder traversals.
        Use the fact that preorder[0] is always the root, and inorder
        splits into left and right subtrees around the root.
        
        Approach: Recursive divide and conquer. Find root in inorder to
        determine left/right subtree sizes, then recursively build
        subtrees with corresponding preorder/inorder slices.
        
        Time complexity: O(n) - each node is visited once with O(1) hashmap lookup.
        Space complexity: O(n) - hashmap storage plus O(h) recursion stack depth.
        */
        if (preorder.empty() || inorder.empty()) return nullptr;
        
        // Create hashmap for O(1) inorder index lookups.
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        preorder_idx = 0;
        return build_subtree(preorder, inorder_map, 0, inorder.size() - 1);
    }
    
private:
    int preorder_idx;
    
    TreeNode* build_subtree(vector<int>& preorder, unordered_map<int, int>& inorder_map, 
                           int left, int right) {
        if (left > right) return nullptr;
        
        // Get root value from preorder and create node.
        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);
        
        // Find root position in inorder to split subtrees.
        int root_idx = inorder_map[root_val];
        
        // Build left subtree first (preorder: root, left, right).
        root->left = build_subtree(preorder, inorder_map, left, root_idx - 1);
        // Build right subtree second.
        root->right = build_subtree(preorder, inorder_map, root_idx + 1, right);
        
        return root;
    }
};
