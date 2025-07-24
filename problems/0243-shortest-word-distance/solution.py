class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        """
        Problem: 0243 - Shortest Word Distance
        
        Find shortest distance between two words in an array.
        Track most recent positions of both words as we scan.
        Update minimum distance whenever we see either word.
        
        Time complexity: O(n) where n is the length of wordsDict.
        Space complexity: O(1).
        """
        min_distance = float('inf')
        pos1 = -1  # Most recent position of word1.
        pos2 = -1  # Most recent position of word2.
        
        # Scan through the array.
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1:
                # Found word1, update its position.
                pos1 = i
                # If we've seen word2, calculate distance.
                if pos2 != -1:
                    min_distance = min(min_distance, pos1 - pos2)
            elif wordsDict[i] == word2:
                # Found word2, update its position.
                pos2 = i
                # If we've seen word1, calculate distance.
                if pos1 != -1:
                    min_distance = min(min_distance, pos2 - pos1)
        
        return min_distance
