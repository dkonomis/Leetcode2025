class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        Problem: 0100 - Same Tree

        Given two binary trees, determine whether they are the same.
        Two trees are the same if they are structurally identical and all node values are equal.

        Approach:
        - Use an iterative Breadth-First Search (BFS) with a queue.
        - Each queue entry is a pair of nodes (one from each tree).
        - At each step:
            - If both nodes are null, continue.
            - If only one is null or values differ, return false.
            - Otherwise, enqueue their left and right children.

        Time complexity: O(n), where n is the number of nodes.
        Space complexity: O(n) for the queue.
        */
        queue<pair<TreeNode*, TreeNode*>> qpair;
        qpair.push({p, q});

        // Iterate while there are node pairs to process.
        while (!qpair.empty()) {
            TreeNode* node1 = qpair.front().first;
            TreeNode* node2 = qpair.front().second;
            qpair.pop();

            // If both nodes are null, continue.
            if (!node1 && !node2) {
                continue;
            }

            // If only one is null or values differ, trees are not the same.
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }

            // Enqueue left children.
            qpair.push({node1->left, node2->left});

            // Enqueue right children.
            qpair.push({node1->right, node2->right});
        }

        return true;
    }
};

