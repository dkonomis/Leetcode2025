class Node:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        """
        Problem: 0146 - LRU Cache
        
        Design a Least Recently Used (LRU) cache with O(1) get and put operations.
        
        Approach:
        Use a doubly linked list to maintain order (most recent at tail, least at head).
        Use a hashmap to store key -> node mappings for O(1) access.
        Dummy head and tail nodes simplify edge cases.
        
        Time complexity: O(1) for both get and put.
        Space complexity: O(capacity).
        """
        self.capacity = capacity
        self.cache = {}  # key -> node mapping.
        
        # Create dummy head and tail nodes.
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node):
        """Remove node from its current position in the list."""
        # Get references to surrounding nodes.
        prev_node = node.prev
        next_node = node.next
        
        # Connect the surrounding nodes to each other.
        prev_node.next = next_node
        next_node.prev = prev_node
        
        # Node is now disconnected from the list.

    def _add_to_tail(self, node):
        """Add node right before tail (most recently used position)."""
        # The node right before tail is currently the most recent.
        prev_node = self.tail.prev
        
        # Insert node between prev_node and tail.
        prev_node.next = node
        node.prev = prev_node
        node.next = self.tail
        self.tail.prev = node
        
        # Node is now the most recently used.

    def get(self, key: int) -> int:
        """Get value for key and mark as recently used."""
        # Check if key exists in cache.
        if key not in self.cache:
            return -1
        
        # Get the node from hashmap.
        node = self.cache[key]
        
        # Move node to tail to mark as most recently used.
        # First remove from current position, then add to tail.
        self._remove(node)
        self._add_to_tail(node)
        
        return node.value

    def put(self, key: int, value: int) -> None:
        """Add or update key-value pair and mark as recently used."""
        if key in self.cache:
            # Key exists - update value and move to tail.
            node = self.cache[key]
            node.value = value
            
            # Move to tail to mark as most recently used.
            self._remove(node)
            self._add_to_tail(node)
        else:
            # Key doesn't exist - create new node.
            node = Node(key, value)
            
            # Add to hashmap and linked list.
            self.cache[key] = node
            self._add_to_tail(node)
            
            # Check if we exceeded capacity.
            if len(self.cache) > self.capacity:
                # Remove least recently used node (right after head).
                lru_node = self.head.next
                
                # Remove from both linked list and hashmap.
                self._remove(lru_node)
                del self.cache[lru_node.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
