class TrieNode:
    def __init__(self):
        # Dictionary to store child nodes for each character.
        self.children = {}
        # Flag to mark if this node represents end of a word.
        self.is_end_of_word = False

class WordDictionary:
    def __init__(self):
        """
        Problem: 0211 - Design Add and Search Words Data Structure
        
        Design data structure to add words and search with wildcard support.
        The '.' character can match any single letter.
        
        Approach: Use Trie data structure with recursive search for wildcards.
        When encountering '.', explore all possible child branches.
        
        Time complexity: O(m) for addWord, O(n * 26^k) for search where k is number of dots.
        Space complexity: O(ALPHABET_SIZE * N * M) where N is number of words, M is average length.
        """
        # Initialize root node of the trie.
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """Add a word to the data structure."""
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
        """Search for a word with wildcard support ('.' matches any letter)."""
        return self._search_helper(word, 0, self.root)
    
    def _search_helper(self, word: str, index: int, node: TrieNode) -> bool:
        """Helper function for recursive wildcard search."""
        # Base case: reached end of word.
        if index == len(word):
            return node.is_end_of_word
        
        char = word[index]
        
        if char == '.':
            # Wildcard: try all possible children.
            for child in node.children.values():
                if self._search_helper(word, index + 1, child):
                    return True
            return False
        else:
            # Regular character: follow exact path.
            if char not in node.children:
                return False
            return self._search_helper(word, index + 1, node.children[char])

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
