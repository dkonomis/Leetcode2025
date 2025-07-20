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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
        Problem: 0102 - Binary Tree Level Order Traversal
        
        Return level order traversal of a binary tree's node values,
        where each level is processed from left to right. Use BFS
        with a queue to process nodes level by level.
        
        Approach: Use a queue to store nodes at current level. For each
        level, process all nodes currently in queue, collect their values,
        and add their children for the next level.
        
        Time complexity: O(n) - visit each node exactly once.
        Space complexity: O(w) - queue stores at most one complete level, where w is maximum tree width.
        */
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;
            
            // Process all nodes at current level.
            for (int i = 0; i < level_size; i++) {
                // Get next node from current level.
                TreeNode* node = q.front();
                q.pop();
                
                // Add value to current level result.
                current_level.push_back(node->val);
                
                // Add children for next level processing.
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add completed level to final result.
            res.push_back(current_level);
        }
        
        return res;
    }
};
