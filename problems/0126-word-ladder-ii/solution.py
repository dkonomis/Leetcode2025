class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        """
        Problem: 0126 - Word Ladder II
        
        Find all shortest transformation sequences from beginWord to endWord.
        
        Approach:
        1. Use BFS to find shortest distance and build parent graph.
        2. Stop BFS when first reaching endWord (shortest distance found).
        3. Use DFS to reconstruct all paths by following parent relationships backward.
        4. Reverse the paths to get correct order.
        
        Time complexity: O(M * N * 26) for BFS + O(K) for DFS where M is word length, N is wordList size, K is number of paths.
        Space complexity: O(N) for parent map and visited set.
        """
        if endWord not in wordList:
            return []
        
        word_set = set(wordList)
        parents = {beginWord: []}
        
        # BFS to build parent graph and find shortest distance.
        queue = [beginWord]
        visited = {beginWord}
        found = False
        
        while queue and not found:
            # Process all words at current level before moving to next level.
            current_level_words = set()
            
            # Process each word in current level.
            for _ in range(len(queue)):
                current = queue.pop(0)
                
                # Try all possible one-letter changes.
                for i in range(len(current)):
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        if c != current[i]:
                            neighbor = current[:i] + c + current[i+1:]
                            
                            # Check if we reached the target word.
                            if neighbor == endWord:
                                found = True
                            
                            # Add neighbor if it's valid and not yet visited.
                            if neighbor in word_set and neighbor not in visited:
                                # Only add to queue once per level.
                                if neighbor not in current_level_words:
                                    current_level_words.add(neighbor)
                                    queue.append(neighbor)
                                    parents[neighbor] = []
                                
                                # Build reverse edge: neighbor <- current.
                                parents[neighbor].append(current)
            
            # Mark all words discovered at this level as visited.
            visited.update(current_level_words)
        
        # DFS to reconstruct all shortest paths.
        res = []
        
        def build_paths(word: str, path: List[str]) -> None:
            # Base case: reached the beginning word.
            if word == beginWord:
                # Reverse path since we built it backward from endWord.
                res.append([beginWord] + path[::-1])
                return
            
            # Recursively explore all parents of current word.
            for parent in parents.get(word, []):
                # Add current word to path and continue with parent.
                build_paths(parent, path + [word])
        
        if found:
            build_paths(endWord, [])
        
        return res
