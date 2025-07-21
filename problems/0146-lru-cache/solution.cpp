class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k = 0, int v = 0) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;  // key -> node mapping.
    Node* head;
    Node* tail;
    
    void _remove(Node* node) {
        // Get references to surrounding nodes.
        Node* prev_node = node->prev;
        Node* next_node = node->next;
        
        // Connect the surrounding nodes to each other.
        prev_node->next = next_node;
        next_node->prev = prev_node;
        
        // Node is now disconnected from the list.
    }
    
    void _add_to_tail(Node* node) {
        // The node right before tail is currently the most recent.
        Node* prev_node = tail->prev;
        
        // Insert node between prev_node and tail.
        prev_node->next = node;
        node->prev = prev_node;
        node->next = tail;
        tail->prev = node;
        
        // Node is now the most recently used.
    }
    
public:
    LRUCache(int capacity) {
        /**
         * Problem: 0146 - LRU Cache
         * 
         * Design a Least Recently Used (LRU) cache with O(1) get and put operations.
         * 
         * Approach:
         * Use a doubly linked list to maintain order (most recent at tail, least at head).
         * Use a hashmap to store key -> node mappings for O(1) access.
         * Dummy head and tail nodes simplify edge cases.
         * 
         * Time complexity: O(1) for both get and put.
         * Space complexity: O(capacity).
         */
        this->capacity = capacity;
        
        // Create dummy head and tail nodes.
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // Check if key exists in cache.
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        // Get the node from hashmap.
        Node* node = cache[key];
        
        // Move node to tail to mark as most recently used.
        // First remove from current position, then add to tail.
        _remove(node);
        _add_to_tail(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists - update value and move to tail.
            Node* node = cache[key];
            node->value = value;
            
            // Move to tail to mark as most recently used.
            _remove(node);
            _add_to_tail(node);
        } else {
            // Key doesn't exist - create new node.
            Node* node = new Node(key, value);
            
            // Add to hashmap and linked list.
            cache[key] = node;
            _add_to_tail(node);
            
            // Check if we exceeded capacity.
            if (cache.size() > capacity) {
                // Remove least recently used node (right after head).
                Node* lru_node = head->next;
                
                // Remove from both linked list and hashmap.
                _remove(lru_node);
                cache.erase(lru_node->key);
                delete lru_node;  // Free memory.
            }
        }
    }
    
    ~LRUCache() {
        // Clean up all nodes.
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
