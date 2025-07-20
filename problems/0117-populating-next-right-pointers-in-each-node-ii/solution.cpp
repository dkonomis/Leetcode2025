/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*
        Problem: 0117 - Populating Next Right Pointers in Each Node II
        
        Populate next pointers to point to next right node in any binary tree.
        
        Approach:
        1. Use BFS (level-order traversal) to process nodes level by level.
        2. For each level, connect consecutive nodes using next pointers.
        3. Last node in each level has next = nullptr (already set).
        4. Works for any binary tree structure (perfect or incomplete).
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(w) where w is maximum width of tree.
        */
        
        if (!root) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            
            // Process all nodes at current level.
            for (int i = 0; i < level_size; i++) {
                Node* node = q.front();
                q.pop();
                
                // Connect to next node in the same level.
                if (i < level_size - 1) {
                    node->next = q.front();
                }
                
                // Add children for next level.
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};
