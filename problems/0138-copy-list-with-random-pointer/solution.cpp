/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        /*
        Problem: 0138 - Copy List with Random Pointer
        
        Create deep copy of linked list with random pointers.
        
        Approach:
        1. Use HashMap to map original nodes to copied nodes.
        2. First pass: create all copied nodes with values only.
        3. Second pass: set next and random pointers using HashMap.
        4. Handle nullptr pointers properly.
        
        Time complexity: O(n) where n is number of nodes.
        Space complexity: O(n) for the HashMap.
        */
        
        if (!head) {
            return nullptr;
        }
        
        // HashMap to store original -> copied node mapping.
        unordered_map<Node*, Node*> node_map;
        
        // First pass: create all copied nodes.
        Node* current = head;
        while (current) {
            node_map[current] = new Node(current->val);
            current = current->next;
        }
        
        // Second pass: set next and random pointers.
        current = head;
        while (current) {
            Node* copied_node = node_map[current];
            
            // Set next pointer.
            if (current->next) {
                copied_node->next = node_map[current->next];
            }
            
            // Set random pointer.
            if (current->random) {
                copied_node->random = node_map[current->random];
            }
            
            current = current->next;
        }
        
        return node_map[head];
    }
};
