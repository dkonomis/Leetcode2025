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
    vector<int> rightSideView(TreeNode* root) {
        /*
         * Problem: 0199 - Binary Tree Right Side View
         * Given root of binary tree, return values of nodes visible from right side
         * ordered from top to bottom (rightmost node at each level).
         * 
         * Approach: Use BFS to traverse level by level. For each level, add the
         * rightmost node's value to result. Process nodes left to right in queue.
         * 
         * Time complexity: O(n).
         * Space complexity: O(w) where w is maximum width of tree.
         */
        
        if (!root) {
            return {};
        }
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        
        // Process each level of the tree.
        while (!q.empty()) {
            int level_size = q.size();
            
            // Process all nodes in current level.
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // If this is the last node in the level, add it to result.
                if (i == level_size - 1) {
                    res.push_back(node->val);
                }
                
                // Add children to queue for next level processing.
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return res;
    }
};
