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
    int countUnivalSubtrees(TreeNode* root) {
        /*
         * Problem: 0250 - Count Univalue Subtrees
         * 
         * Count subtrees where all nodes have the same value.
         * Use post-order traversal to check each subtree bottom-up.
         * Return pair: (is_univalue, count) from each subtree.
         * 
         * Time complexity: O(n) where n is the number of nodes.
         * Space complexity: O(h) where h is the height of the tree.
         */
        
        // Get the total count from the root.
        return helper(root).second;
    }
    
private:
    pair<bool, int> helper(TreeNode* node) {
        // Base case: empty tree is univalue with 0 count.
        if (!node) {
            return {true, 0};
        }
        
        // Check left and right subtrees recursively.
        auto [left_is_uni, left_count] = helper(node->left);
        auto [right_is_uni, right_count] = helper(node->right);
        
        // Start with count from children.
        int count = left_count + right_count;
        
        // Check if current subtree is univalue.
        bool is_uni = true;
        
        // Must have univalue children.
        if (!left_is_uni || !right_is_uni) {
            is_uni = false;
        }
        
        // Check if current node matches its children.
        if (node->left && node->left->val != node->val) {
            is_uni = false;
        }
        if (node->right && node->right->val != node->val) {
            is_uni = false;
        }
        
        // If this is a univalue subtree, increment count.
        if (is_uni) {
            count++;
        }
        
        // Return whether current subtree is univalue and total count.
        return {is_uni, count};
    }
};
