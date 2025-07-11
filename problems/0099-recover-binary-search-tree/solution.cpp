class Solution {
public:
    void recoverTree(TreeNode* root) {
        /*
        Problem: 0099 - Recover Binary Search Tree

        Two nodes in a binary search tree are swapped by mistake.
        Recover the BST without changing its structure.

        Approach:
        - Use an iterative inorder traversal (left-root-right).
        - Track the previous visited node.
        - A violation occurs when the current node's value < previous node's value.
        - On first violation, record the 'first' and 'second' nodes.
        - On second violation (if any), update 'second' only.
        - After traversal, swap the values of 'first' and 'second'.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(h), where h is the height of the tree.
        */

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        stack<TreeNode*> stk;
        TreeNode* current = root;

        // Perform iterative inorder traversal.
        while (!stk.empty() || current) {
            // Traverse as far left as possible.
            while (current) {
                stk.push(current);
                current = current->left;
            }

            // Visit node from top of the stack.
            current = stk.top();
            stk.pop();

            // Detect violation of BST property.
            if (prev && current->val < prev->val) {
                if (!first) {
                    first = prev;
                    second = current;
                } else {
                    second = current;
                }
            }

            // Update previous node.
            prev = current;

            // Move to right subtree.
            current = current->right;
        }

        // Swap the values of the two incorrect nodes.
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

