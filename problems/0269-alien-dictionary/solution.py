class Solution:
    def alienOrder(self, words: List[str]) -> str:
        """
        Problem: 0269 - Alien Dictionary
        
        Find the order of characters in an alien language given a sorted dictionary.
        
        Approach: Build a directed graph where edge u->v means u comes before v. Use
        topological sort to find the character ordering. Detect cycles (invalid order)
        and handle edge cases like prefix/suffix conflicts.
        
        Time complexity: O(C) where C is total number of characters across all words.
        Space complexity: O(1) since at most 26 lowercase English letters.
        """
        # Build adjacency list and track all unique characters.
        graph = {}
        in_degree = {}
        
        # Initialize graph with all characters.
        for word in words:
            for c in word:
                if c not in graph:
                    graph[c] = set()
                    in_degree[c] = 0
        
        # Build graph by comparing adjacent words.
        for i in range(len(words) - 1):
            word1, word2 = words[i], words[i + 1]
            
            # Find first differing character.
            min_len = min(len(word1), len(word2))
            found_diff = False
            
            for j in range(min_len):
                if word1[j] != word2[j]:
                    # Add edge word1[j] -> word2[j].
                    if word2[j] not in graph[word1[j]]:
                        graph[word1[j]].add(word2[j])
                        in_degree[word2[j]] += 1
                    found_diff = True
                    break
            
            # Check invalid case: word1 is prefix of word2 but longer.
            if not found_diff and len(word1) > len(word2):
                return ""
        
        # Topological sort using Kahn's algorithm.
        queue = []
        for c in in_degree:
            if in_degree[c] == 0:
                queue.append(c)
        
        res = []
        while queue:
            # Process character with no dependencies.
            c = queue.pop(0)
            res.append(c)
            
            # Update neighbors.
            for neighbor in graph[c]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
        
        # Check if all characters were processed (no cycle).
        if len(res) != len(graph):
            return ""
        
        return "".join(res)
