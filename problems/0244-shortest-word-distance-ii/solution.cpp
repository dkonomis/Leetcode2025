class WordDistance {
public:
    /*
     * Problem: 0244 - Shortest Word Distance II
     * 
     * Design data structure for multiple shortest distance queries.
     * Preprocess word positions in constructor using hash map.
     * For each query, use two pointers on position lists.
     * 
     * Time complexity: O(n) for constructor, O(m + n) for shortest query.
     * Space complexity: O(n) where n is the length of wordsDict.
     */
    
    WordDistance(vector<string>& wordsDict) {
        // Build position lists for each word.
        for (int i = 0; i < wordsDict.size(); i++) {
            word_positions[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        // Get position lists for both words.
        vector<int>& positions1 = word_positions[word1];
        vector<int>& positions2 = word_positions[word2];
        
        // Use two pointers to find minimum distance.
        int i = 0, j = 0;
        int min_distance = INT_MAX;
        
        // Compare all pairs efficiently.
        while (i < positions1.size() && j < positions2.size()) {
            // Calculate distance between current positions.
            min_distance = min(min_distance, abs(positions1[i] - positions2[j]));
            
            // Move pointer with smaller position.
            if (positions1[i] < positions2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return min_distance;
    }
    
private:
    // Store all positions for each word.
    un
