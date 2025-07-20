/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private:
    ListNode* current;

public:
    TreeNode* sortedListToBST(ListNode* head) {
        /*
        Problem: 0109 - Convert Sorted List to Binary Search Tree
        
        Convert a sorted linked list to a height-balanced BST.
        
        Approach:
        1. Count total nodes to determine tree structure.
        2. Use inorder simulation - build left subtree, process current node, build right subtree.
        3. Advance list pointer as we consume nodes in inorder fashion.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(log n) for recursion stack.
        */
        
        if (!head) {
            return nullptr;
        }
        
        // Count total nodes in the list.
        ListNode* temp = head;
        int size = 0;
        while (temp) {
            size++;
            temp = temp->next;
        }
        
        // Initialize the current pointer.
        current = head;
        
        function<TreeNode*(int, int)> build_tree = [&](int start, int end) -> TreeNode* {
            // Base case: no nodes to process.
            if (start > end) {
                return nullptr;
            }
            
            // Calculate middle position.
            int mid = (start + end) / 2;
            
            // Build left subtree first (inorder: left, root, right).
            TreeNode* left_child = build_tree(start, mid - 1);
            
            // Process current node (this is the "root" step in inorder).
            TreeNode* root = new TreeNode(current->val);
            current = current->next;
            
            // Build right subtree.
            TreeNode* right_child = build_tree(mid + 1, end);
            
            // Connect children.
            root->left = left_child;
            root->right = right_child;
            
            return root;
        };
        
        return build_tree(0, size - 1);
    }
};
