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
    int maxDepth(TreeNode* root) {
        /*
        Problem: 0104 - Maximum Depth of Binary Tree
        
        Find the maximum depth of a binary tree using iterative DFS with
        a stack. Track each node with its current depth and maintain
        the maximum depth seen so far.
        
        Approach: Use a stack to store (node, depth) pairs. Process each
        node by checking if its depth is the new maximum, then add its
        children with incremented depth to the stack.
        
        Time complexity: O(n) - visit each node exactly once.
        Space complexity: O(h) - stack stores at most h nodes, where h is tree height.
        */
        if (!root) return 0;
        
        // Stack stores pairs of (node, depth).
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int max_depth = 0;
        
        while (!st.empty()) {
            // Get next node and its depth from stack.
            auto [node, depth] = st.top();
            st.pop();
            
            // Update maximum depth if current depth is greater.
            max_depth = max(max_depth, depth);
            
            // Add children with incremented depth to stack.
            if (node->left) st.push({node->left, depth + 1});
            if (node->right) st.push({node->right, depth + 1});
        }
        
        return max_depth;
    }
};
