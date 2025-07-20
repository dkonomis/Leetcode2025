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
    bool isSymmetric(TreeNode* root) {
        /*
        Problem: 0101 - Symmetric Tree
        
        Check if a binary tree is symmetric around its center using
        an iterative approach with a queue. For symmetry, we compare
        nodes in pairs: left subtree's left with right subtree's right,
        and left subtree's right with right subtree's left.
        
        Approach: Use a queue to store pairs of nodes that should be
        mirrors of each other. Process pairs level by level.
        
        Time complexity: O(n) - visit each node once.
        Space complexity: O(w) - queue size equals maximum tree width.
        */
        if (!root) return true;
        
        // Queue stores pairs of nodes that should be mirrors.
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        
        while (!q.empty()) {
            auto [left, right] = q.front();
            q.pop();
            
            // Both nodes are null - continue checking other pairs.
            if (!left && !right) continue;
            
            // One node is null, the other isn't - not symmetric.
            if (!left || !right) return false;
            
            // Values don't match - not symmetric.
            if (left->val != right->val) return false;
            
            // Add mirror pairs to queue for next iteration.
            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }
        
        return true;
    }
};
