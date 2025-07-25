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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        /**
         * Problem: 0272 - Closest Binary Search Tree Value II
         * 
         * Find k values in BST closest to target.
         * 
         * Approach: In-order traversal with sliding window. Maintain k closest values
         * seen so far. When window is full, compare new value with furthest value in
         * window and keep the closer one.
         * 
         * Time complexity: O(n) where n is number of nodes in the tree.
         * Space complexity: O(k) for storing k closest values.
         */
        
        deque<int> closest;
        inorder(root, target, k, closest);
        
        // Convert deque to vector for return.
        return vector<int>(closest.begin(), closest.end());
    }
    
private:
    void inorder(TreeNode* node, double target, int k, deque<int>& closest) {
        if (!node) {
            return;
        }
        
        // Process left subtree.
        inorder(node->left, target, k, closest);
        
        // Process current node.
        if (closest.size() < k) {
            // Window not full, just add.
            closest.push_back(node->val);
        } else {
            // Window full, check if current is closer than furthest.
            // In ascending order, furthest from target is either first or last.
            if (abs(node->val - target) < abs(closest[0] - target)) {
                closest.pop_front();
                closest.push_back(node->val);
            } else {
                // Current node and all subsequent nodes are further away.
                return;
            }
        }
        
        // Process right subtree.
        inorder(node->right, target, k, closest);
    }
};
