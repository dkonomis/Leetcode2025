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
    bool hasPathSum(TreeNode* root, int targetSum) {
        /*
        Problem: 0112 - Path Sum
        
        Check if there exists a root-to-leaf path with given target sum.
        
        Approach:
        1. Use iterative DFS with a stack to traverse all root-to-leaf paths.
        2. Store (node, remaining_sum) pairs in the stack.
        3. At leaf nodes, check if remaining sum equals node value.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for stack.
        */
        
        if (!root) {
            return false;
        }
        
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, targetSum});
        
        while (!stk.empty()) {
            auto [node, remaining] = stk.top();
            stk.pop();
            
            // Check if we've reached a leaf with the exact remaining sum.
            if (!node->left && !node->right) {
                if (node->val == remaining) {
                    return true;
                }
                continue;
            }
            
            // Add children to stack with reduced remaining sum.
            if (node->left) {
                stk.push({node->left, remaining - node->val});
            }
            if (node->right) {
                stk.push({node->right, remaining - node->val});
            }
        }
        
        return false;
    }
};
