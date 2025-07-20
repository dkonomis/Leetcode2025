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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        /*
        Problem: 0113 - Path Sum II
        
        Return all root-to-leaf paths where the sum equals targetSum.
        
        Approach:
        1. Use backtracking to explore all root-to-leaf paths.
        2. Build current path as we traverse down the tree.
        3. When reaching a leaf with correct sum, add path copy to results.
        4. Backtrack by removing current node when returning.
        
        Time complexity: O(n * h) where n is number of nodes and h is height.
        Space complexity: O(h) for recursion stack and path storage.
        */
        
        if (!root) {
            return {};
        }
        
        vector<vector<int>> res;
        vector<int> path;
        
        function<void(TreeNode*, int)> backtrack = [&](TreeNode* node, int remaining) -> void {
            // Add current node to path.
            path.push_back(node->val);
            
            // Check if we've reached a leaf with the exact remaining sum.
            if (!node->left && !node->right) {
                if (node->val == remaining) {
                    res.push_back(path);  // Vector automatically copies.
                }
            } else {
                // Continue exploring children.
                int new_remaining = remaining - node->val;
                if (node->left) {
                    backtrack(node->left, new_remaining);
                }
                if (node->right) {
                    backtrack(node->right, new_remaining);
                }
            }
            
            // Backtrack: remove current node from path.
            path.pop_back();
        };
        
        backtrack(root, targetSum);
        return res;
    }
};
