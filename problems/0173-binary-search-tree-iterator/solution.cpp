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

class BSTIterator {
public:
    /*
    Problem: 0173 - Binary Search Tree Iterator
    
    Implement iterator over in-order traversal of BST with O(1) average time and O(h) space.
    Use stack to simulate in-order traversal on-demand instead of pre-computing all values.
    
    Approach:
    - Maintain stack containing path from root to current leftmost node
    - next(): Pop from stack (current smallest), push right subtree's left path
    - hasNext(): Check if stack is non-empty
    - Key insight: In-order traversal visits left, root, right
    
    Time complexity: O(1) average for both operations.
    Space complexity: O(h) where h is height of tree.
    */
    
    BSTIterator(TreeNode* root) {
        // Push all left nodes from root to establish initial state.
        pushLeftPath(root);
    }
    
    int next() {
        // Pop the next node (smallest unvisited).
        TreeNode* node = stack.top();
        stack.pop();
        
        // If this node has right subtree, push its left path.
        // This maintains the in-order property.
        if (node->right) {
            pushLeftPath(node->right);
        }
        
        return node->val;
    }
    
    bool hasNext() {
        // Check if there are more elements to iterate.
        return !stack.empty();
    }

private:
    stack<TreeNode*> stack;
    
    void pushLeftPath(TreeNode* node) {
        // Helper method to push all left nodes starting from given node.
        // This simulates going to the leftmost node in in-order traversal.
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
