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
    int minDepth(TreeNode* root) {
        /*
        Problem: 0111 - Minimum Depth of Binary Tree
        
        Find the minimum depth to the nearest leaf node.
        
        Approach:
        1. Use BFS (level-order traversal) to explore nodes level by level.
        2. Return depth as soon as we encounter the first leaf node.
        3. BFS guarantees we find the minimum depth first.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(w) where w is maximum width of tree.
        */
        
        if (!root) {
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            
            // Check if current node is a leaf.
            if (!node->left && !node->right) {
                return depth;
            }
            
            // Add children to queue with incremented depth.
            if (node->left) {
                q.push({node->left, depth + 1});
            }
            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }
        
        return 0;
    }
};
