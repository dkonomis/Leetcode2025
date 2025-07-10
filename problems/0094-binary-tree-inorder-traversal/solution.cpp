class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        /*
        Problem: 0094 - Binary Tree Inorder Traversal

        Given the root of a binary tree, return the inorder traversal of its nodes' values.

        Approach:
        - Use an explicit stack to simulate the recursive inorder traversal.
        - Traverse left down the tree, pushing nodes onto the stack.
        - When reaching null, pop from the stack, visit the node,
          and move to its right child.
        - Repeat until all nodes have been visited.

        Time complexity: O(n), where n is the number of nodes in the tree.
        Space complexity: O(h), where h is the height of the tree (stack depth).
        */
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* current = root;

        // Traverse the tree using an explicit stack.
        while (current != nullptr || !stk.empty()) {
            // Go as left as possible, pushing nodes onto the stack.
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }

            // Visit the node on top of the stack.
            current = stk.top();
            stk.pop();
            res.push_back(current->val);

            // Move to the right child.
            current = current->right;
        }

        return res;
    }
};

