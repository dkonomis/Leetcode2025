/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        /*
        Problem: 0133 - Clone Graph
        
        Create a deep copy of connected undirected graph.
        
        Approach:
        1. Use BFS to traverse all nodes in the graph.
        2. Use hashmap to track original -> cloned node mapping.
        3. For each node, clone it and all its neighbors.
        4. Connect cloned nodes to cloned neighbors.
        
        Time complexity: O(V + E) where V is vertices and E is edges.
        Space complexity: O(V) for hashmap and queue.
        */
        
        if (!node) {
            return nullptr;
        }
        
        // HashMap to store original -> cloned node mapping.
        unordered_map<Node*, Node*> cloned;
        
        // BFS queue starting with the given node.
        queue<Node*> q;
        q.push(node);
        cloned[node] = new Node(node->val);
        
        while (!q.empty()) {
            // Dequeue from front for BFS (FIFO order).
            Node* current = q.front();
            q.pop();
            
            // Process all neighbors of current node.
            for (Node* neighbor : current->neighbors) {
                // If neighbor hasn't been cloned yet, clone it and add to queue.
                if (cloned.find(neighbor) == cloned.end()) {
                    cloned[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                
                // Connect cloned current node to cloned neighbor.
                cloned[current]->neighbors.push_back(cloned[neighbor]);
            }
        }
        
        // Return the cloned version of the original starting node.
        return cloned[node];
    }
};
