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
    int sumNumbers(TreeNode* root) {
        /*
        Problem: 0129 - Sum Root to Leaf Numbers
        
        Calculate sum of all root-to-leaf numbers in binary tree.
        
        Approach:
        1. Use iterative DFS with explicit stack.
        2. Stack stores (node, current_number) pairs.
        3. Build numbers incrementally as we traverse down.
        4. When reaching a leaf, add complete number to total sum.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(h) where h is height of tree for stack.
        */
        
        if (!root) {
            return 0;
        }
        
        int total_sum = 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        
        while (!stk.empty()) {
            auto [node, current_number] = stk.top();
            stk.pop();
            
            // Build the current number by appending node's digit.
            current_number = current_number * 10 + node->val;
            
            // Check if we've reached a leaf node.
            if (!node->left && !node->right) {
                total_sum += current_number;
            } else {
                // Add children to stack with updated number.
                if (node->right) {
                    stk.push({node->right, current_number});
                }
                if (node->left) {
                    stk.push({node->left, current_number});
                }
            }
        }
        
        return total_sum;
    }
};
