class WordDistance:
    """
    Problem: 0244 - Shortest Word Distance II
    
    Design data structure for multiple shortest distance queries.
    Preprocess word positions in constructor using hash map.
    For each query, use two pointers on position lists.
    
    Time complexity: O(n) for constructor, O(m + n) for shortest query.
    Space complexity: O(n) where n is the length of wordsDict.
    """

    def __init__(self, wordsDict: List[str]):
        # Store all positions for each word.
        self.word_positions = {}
        
        # Build position lists for each word.
        for i, word in enumerate(wordsDict):
            if word not in self.word_positions:
                self.word_positions[word] = []
            self.word_positions[word].append(i)

    def shortest(self, word1: str, word2: str) -> int:
        # Get position lists for both words.
        positions1 = self.word_positions[word1]
        positions2 = self.word_positions[word2]
        
        # Use two pointers to find minimum distance.
        i, j = 0, 0
        min_distance = float('inf')
        
        # Compare all pairs efficiently.
        while i < len(positions1) and j < len(positions2):
            # Calculate distance between current positions.
            min_distance = min(min_distance, abs(positions1[i] - positions2[j]))
            
            # Move pointer with smaller position.
            if positions1[i] < positions2[j]:
                i += 1
            else:
                j += 1
        
        return min_distance


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(wordsDict)
# param_1 = obj.shortest(word1,word2)
