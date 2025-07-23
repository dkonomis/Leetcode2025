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

class WordDictionary {
private:
    TrieNode* root;
    
public:
    /*
     * Problem: 0211 - Design Add and Search Words Data Structure
     * Design data structure to add words and search with wildcard support.
     * The '.' character can match any single letter.
     * 
     * Approach: Use Trie data structure with recursive search for wildcards.
     * When encountering '.', explore all possible child branches.
     * 
     * Time complexity: O(m) for addWord, O(n * 26^k) for search where k is number of dots.
     * Space complexity: O(ALPHABET_SIZE * N * M) where N is number of words, M is average length.
     */
    
    WordDictionary() {
        // Initialize root node of the trie.
        root = new TrieNode();
    }
    
    void addWord(string word) {
        // Add a word to the data structure.
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
        // Search for a word with wildcard support ('.' matches any letter).
        return searchHelper(word, 0, root);
    }
    
private:
    bool searchHelper(const string& word, int index, TrieNode* node) {
        // Helper function for recursive wildcard search.
        
        // Base case: reached end of word.
        if (index == word.length()) {
            return node->is_end_of_word;
        }
        
        char c = word[index];
        
        if (c == '.') {
            // Wildcard: try all possible children.
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            // Regular character: follow exact path.
            int charIndex = c - 'a';
            if (node->children[charIndex] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[charIndex]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
