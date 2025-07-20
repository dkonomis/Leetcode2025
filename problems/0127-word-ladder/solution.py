class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        """
        Problem: 0127 - Word Ladder
        
        Find the length of shortest transformation sequence from beginWord to endWord.
        
        Approach:
        1. Build a graph using intermediate states (e.g., "h*t" connects "hit" and "hot").
        2. Use BFS to find shortest path length.
        3. Each intermediate state groups words that differ by exactly one letter.
        4. Much faster than generating all possible neighbors on-the-fly.
        
        Time complexity: O(M * N) where M is word length and N is wordList size.
        Space complexity: O(M * N) for the graph and visited set.
        """
        if endWord not in wordList:
            return 0
        
        L = len(beginWord)
        
        # Build graph using intermediate states.
        graph = {}
        for word in wordList:
            for i in range(L):
                # Create intermediate state by replacing one letter with '*'.
                key = word[:i] + '*' + word[i+1:]
                if key not in graph:
                    graph[key] = []
                graph[key].append(word)
        
        # BFS to find shortest transformation sequence.
        queue = [(beginWord, 1)]
        visited = {beginWord}
        
        while queue:
            word, level = queue.pop(0)
            
            # Try all intermediate states for current word.
            for i in range(L):
                key = word[:i] + '*' + word[i+1:]
                
                # Check all words connected through this intermediate state.
                for neighbor in graph.get(key, []):
                    # Found the target word!
                    if neighbor == endWord:
                        return level + 1
                    
                    # Add unvisited neighbor to queue.
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, level + 1))
        
        # No transformation sequence found.
        return 0
