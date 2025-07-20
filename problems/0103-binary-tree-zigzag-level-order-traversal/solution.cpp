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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /*
        Problem: 0103 - Binary Tree Zigzag Level Order Traversal
        
        Return zigzag level order traversal where odd levels go left to right
        and even levels go right to left. Use BFS with a regular queue and
        insert values at front or back of current level based on direction.
        
        Approach: Standard BFS level order traversal, but alternate inserting
        at the beginning vs end of current level list to achieve zigzag effect.
        
        Time complexity: O(n) - visit each node exactly once.
        Space complexity: O(w) - queue stores at most one complete level, where w is maximum tree width.
        */
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        
        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level;
            
            // Process all nodes at current level.
            for (int i = 0; i < level_size; i++) {
                // Get next node from current level.
                TreeNode* node = q.front();
                q.pop();
                
                if (left_to_right) {
                    // Add value to end of current level.
                    current_level.push_back(node->val);
                } else {
                    // Add value to front of current level.
                    current_level.insert(current_level.begin(), node->val);
                }
                
                // Add children for next level processing.
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add completed level to final result.
            res.push_back(current_level);
            // Flip direction for next level.
            left_to_right = !left_to_right;
        }
        
        return res;
    }
};
