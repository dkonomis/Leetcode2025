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
    vector<string> binaryTreePaths(TreeNode* root) {
        /**
         * Problem: 0257 - Binary Tree Paths
         * 
         * Find all root-to-leaf paths using iterative DFS with a stack.
         * Maintain parallel stacks for nodes and their corresponding paths.
         * When we pop a leaf node, add its path to results.
         * 
         * Time complexity: O(n) where n is the number of nodes.
         * Space complexity: O(n) for the stacks and output.
         */
        
        vector<string> res;
        if (!root) return res;
        
        // Stack of (node, path_to_node) pairs.
        stack<pair<TreeNode*, string>> stk;
        stk.push({root, to_string(root->val)});
        
        while (!stk.empty()) {
            TreeNode* node = stk.top().first;
            string path = stk.top().second;
            stk.pop();
            
            // If leaf node, add path to results.
            if (!node->left && !node->right) {
                res.push_back(path);
                continue;
            }
            
            // Push children with updated paths.
            if (node->right) {
                stk.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if (node->left) {
                stk.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }
        
        return res;
    }
};
