class TrieNode:
    """Node in the Trie data structure."""
    def __init__(self):
        # Dictionary to store child nodes for each character.
        self.children = {}
        # The complete word ending at this node (None if not end of word).
        self.word = None

class Trie:
    """Trie (prefix tree) data structure for efficient word storage and retrieval."""
    
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str) -> None:
        """Insert a word into the Trie."""
        current = self.root
        
        # Traverse through each character in the word.
        for char in word:
            # If character doesn't exist, create new node.
            if char not in current.children:
                current.children[char] = TrieNode()
            # Move to the child node.
            current = current.children[char]
        
        # Store the complete word at the end node.
        current.word = word
    
    def search_from_node(self, node: TrieNode, char: str) -> TrieNode:
        """
        Search for a character from given node, return next node or None.
        Used for navigating Trie during board traversal.
        """
        if char in node.children:
            return node.children[char]
        return None
    
    def has_word_at_node(self, node: TrieNode) -> str:
        """
        Check if given node represents end of a word.
        Returns the word if found, None otherwise.
        """
        return node.word
    
    def remove_word_at_node(self, node: TrieNode) -> None:
        """
        Remove word at given node to prevent duplicates.
        Optimization for word search problems.
        """
        node.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        """
        Problem: 0212 - Word Search II
        
        Given 2D board and list of words, return all words that can be found on board.
        Words are formed by sequentially adjacent cells (no diagonal, no reuse).
        
        Approach: Build Trie from words, then DFS from each board cell. Use Trie to
        efficiently search multiple words simultaneously during single traversal.
        
        Time complexity: O(M * N * 4^L) where M,N are board dimensions, L is max word length.
        Space complexity: O(W * L) where W is number of words, L is average word length.
        """
        # Build Trie from all words for efficient multi-word search.
        trie = Trie()
        for word in words:
            trie.insert(word)
        
        rows, cols = len(board), len(board[0])
        found_words = []
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up.
        
        def dfs(row: int, col: int, node: TrieNode) -> None:
            """DFS to search words starting from current board position."""
            # Bounds check.
            if row < 0 or row >= rows or col < 0 or col >= cols:
                return
            
            char = board[row][col]
            
            # If character already visited (marked with '#').
            if char == '#':
                return
            
            # Try to move to next node in Trie.
            next_node = trie.search_from_node(node, char)
            if not next_node:
                return
            
            # Check if we found a complete word.
            word = trie.has_word_at_node(next_node)
            if word:
                found_words.append(word)
                # Remove word to avoid duplicates (optimization).
                trie.remove_word_at_node(next_node)
            
            # Mark current cell as visited.
            board[row][col] = '#'
            
            # Explore all 4 directions.
            for dr, dc in directions:
                dfs(row + dr, col + dc, next_node)
            
            # Backtrack: restore original character.
            board[row][col] = char
        
        # Start DFS from each cell in the board.
        for i in range(rows):
            for j in range(cols):
                # Only start if first character exists in Trie.
                if trie.search_from_node(trie.root, board[i][j]):
                    dfs(i, j, trie.root)
        
        return found_words
