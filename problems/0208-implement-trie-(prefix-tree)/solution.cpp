class TrieNode {
public:
    // Array to store child nodes for each character (a-z).
    TrieNode* children[26];
    // Flag to mark if this node represents end of a word.
    bool is_end_of_word;
    
    TrieNode() {
        // Initialize all children to nullptr.
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        is_end_of_word = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    /*
     * Problem: 0208 - Implement Trie (Prefix Tree)
     * Initialize Trie data structure for efficient string storage and retrieval.
     * Supports insert, search, and prefix matching operations.
     * 
     * Approach: Use tree structure where each node contains children array
     * and end-of-word flag. Navigate through characters to build/search paths.
     * 
     * Time complexity: O(m) for all operations where m is word/prefix length.
     * Space complexity: O(ALPHABET_SIZE * N * M) where N is number of words, M is average length.
     */
    
    Trie() {
        // Initialize root node of the trie.
        root = new TrieNode();
    }
    
    void insert(string word) {
        // Insert a word into the trie.
        TrieNode* current = root;
        
        // Traverse through each character in the word.
        for (char c : word) {
            int index = c - 'a';
            // If character doesn't exist, create new node.
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            // Move to the child node.
            current = current->children[index];
        }
        
        // Mark the end of word.
        current->is_end_of_word = true;
    }
    
    bool search(string word) {
        // Search for exact word in the trie.
        TrieNode* current = root;
        
        // Traverse through each character in the word.
        for (char c : word) {
            int index = c - 'a';
            // If character doesn't exist, word not found.
            if (current->children[index] == nullptr) {
                return false;
            }
            // Move to the child node.
            current = current->children[index];
        }
        
        // Return true only if we reached end of a complete word.
        return current->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        // Check if any word in trie starts with given prefix.
        TrieNode* current = root;
        
        // Traverse through each character in the prefix.
        for (char c : prefix) {
            int index = c - 'a';
            // If character doesn't exist, prefix not found.
            if (current->children[index] == nullptr) {
                return false;
            }
            // Move to the child node.
            current = current->children[index];
        }
        
        // If we successfully traversed all prefix characters, prefix exists.
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
