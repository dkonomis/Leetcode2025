class TrieNode:
    def __init__(self):
        # Dictionary to store child nodes for each character.
        self.children = {}
        # Flag to mark if this node represents end of a word.
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        """
        Problem: 0208 - Implement Trie (Prefix Tree)
        
        Initialize Trie data structure for efficient string storage and retrieval.
        Supports insert, search, and prefix matching operations.
        
        Approach: Use tree structure where each node contains children dictionary
        and end-of-word flag. Navigate through characters to build/search paths.
        
        Time complexity: O(m) for all operations where m is word/prefix length.
        Space complexity: O(ALPHABET_SIZE * N * M) where N is number of words, M is average length.
        """
        # Initialize root node of the trie.
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """Insert a word into the trie."""
        current = self.root
        
        # Traverse through each character in the word.
        for char in word:
            # If character doesn't exist, create new node.
            if char not in current.children:
                current.children[char] = TrieNode()
            # Move to the child node.
            current = current.children[char]
        
        # Mark the end of word.
        current.is_end_of_word = True

    def search(self, word: str) -> bool:
        """Search for exact word in the trie."""
        current = self.root
        
        # Traverse through each character in the word.
        for char in word:
            # If character doesn't exist, word not found.
            if char not in current.children:
                return False
            # Move to the child node.
            current = current.children[char]
        
        # Return true only if we reached end of a complete word.
        return current.is_end_of_word

    def startsWith(self, prefix: str) -> bool:
        """Check if any word in trie starts with given prefix."""
        current = self.root
        
        # Traverse through each character in the prefix.
        for char in prefix:
            # If character doesn't exist, prefix not found.
            if char not in current.children:
                return False
            # Move to the child node.
            current = current.children[char]
        
        # If we successfully traversed all prefix characters, prefix exists.
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
