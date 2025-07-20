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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /*
        Problem: 0107 - Binary Tree Level Order Traversal II
        
        Return the bottom-up level order traversal of binary tree nodes.
        
        Approach:
        1. Use BFS (queue) to traverse level by level.
        2. For each level, process all nodes and collect their values.
        3. Insert each level at beginning for bottom-up order.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(w) where w is maximum width of tree.
        */
        
        if (!root) {
            return {};
        }
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> level_nodes;
            
            // Process all nodes at current level.
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level_nodes.push_back(node->val);
                
                // Add children for next level.
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            // Insert at beginning for bottom-up order.
            res.insert(res.begin(), level_nodes);
        }
        
        return res;
    }
};
