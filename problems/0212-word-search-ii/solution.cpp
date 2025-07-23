class TrieNode {
public:
    // Array to store child nodes for each character (a-z).
    TrieNode* children[26];
    // The complete word ending at this node (empty if not end of word).
    string word;
    
    TrieNode() {
        // Initialize all children to nullptr.
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    // Trie (prefix tree) data structure for efficient word storage and retrieval.
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        // Insert a word into the Trie.
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
        
        // Store the complete word at the end node.
        current->word = word;
    }
    
    TrieNode* searchFromNode(TrieNode* node, char c) {
        // Search for a character from given node, return next node or nullptr.
        // Used for navigating Trie during board traversal.
        int index = c - 'a';
        if (node->children[index] != nullptr) {
            return node->children[index];
        }
        return nullptr;
    }
    
    string hasWordAtNode(TrieNode* node) {
        // Check if given node represents end of a word.
        // Returns the word if found, empty string otherwise.
        return node->word;
    }
    
    void removeWordAtNode(TrieNode* node) {
        // Remove word at given node to prevent duplicates.
        // Optimization for word search problems.
        node->word = "";
    }
    
    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /*
         * Problem: 0212 - Word Search II
         * Given 2D board and list of words, return all words that can be found on board.
         * Words are formed by sequentially adjacent cells (no diagonal, no reuse).
         * 
         * Approach: Build Trie from words, then DFS from each board cell. Use Trie to
         * efficiently search multiple words simultaneously during single traversal.
         * 
         * Time complexity: O(M * N * 4^L) where M,N are board dimensions, L is max word length.
         * Space complexity: O(W * L) where W is number of words, L is average word length.
         */
        
        // Build Trie from all words for efficient multi-word search.
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        
        int rows = board.size();
        int cols = board[0].size();
        vector<string> found_words;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // right, down, left, up.
        
        function<void(int, int, TrieNode*)> dfs = [&](int row, int col, TrieNode* node) -> void {
            // DFS to search words starting from current board position.
            
            // Bounds check.
            if (row < 0 || row >= rows || col < 0 || col >= cols) {
                return;
            }
            
            char c = board[row][col];
            
            // If character already visited (marked with '#').
            if (c == '#') {
                return;
            }
            
            // Try to move to next node in Trie.
            TrieNode* next_node = trie.searchFromNode(node, c);
            if (next_node == nullptr) {
                return;
            }
            
            // Check if we found a complete word.
            string word = trie.hasWordAtNode(next_node);
            if (!word.empty()) {
                found_words.push_back(word);
                // Remove word to avoid duplicates (optimization).
                trie.removeWordAtNode(next_node);
            }
            
            // Mark current cell as visited.
            board[row][col] = '#';
            
            // Explore all 4 directions.
            for (const auto& [dr, dc] : directions) {
                dfs(row + dr, col + dc, next_node);
            }
            
            // Backtrack: restore original character.
            board[row][col] = c;
        };
        
        // Start DFS from each cell in the board.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Only start if first character exists in Trie.
                if (trie.searchFromNode(trie.getRoot(), board[i][j]) != nullptr) {
                    dfs(i, j, trie.getRoot());
                }
            }
        }
        
        return found_words;
    }
};
