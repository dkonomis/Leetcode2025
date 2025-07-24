class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        /*
         * Problem: 0245 - Shortest Word Distance III
         * 
         * Find shortest distance between two words that may be the same.
         * If words are same, find distance between two different occurrences.
         * Track most recent position(s) and update minimum distance.
         * 
         * Time complexity: O(n) where n is the length of wordsDict.
         * Space complexity: O(1).
         */
        
        int min_distance = INT_MAX;
        
        if (word1 == word2) {
            // Words are same, find distance between different occurrences.
            int prev_pos = -1;
            
            for (int i = 0; i < wordsDict.size(); i++) {
                if (wordsDict[i] == word1) {
                    // Found the word.
                    if (prev_pos != -1) {
                        // Calculate distance from previous occurrence.
                        min_distance = min(min_distance, i - prev_pos);
                    }
                    // Update previous position.
                    prev_pos = i;
                }
            }
        } else {
            // Words are different, use two-pointer approach.
            int pos1 = -1;  // Most recent position of word1.
            int pos2 = -1;  // Most recent position of word2.
            
            for (int i = 0; i < wordsDict.size(); i++) {
                if (wordsDict[i] == word1) {
                    // Found word1, update its position.
                    pos1 = i;
                    // If we've seen word2, calculate distance.
                    if (pos2 != -1) {
                        min_distance = min(min_distance, pos1 - pos2);
                    }
                } else if (wordsDict[i] == word2) {
                    // Found word2, update its position.
                    pos2 = i;
                    // If we've seen word1, calculate distance.
                    if (pos1 != -1) {
                        min_distance = min(min_distance, pos2 - pos1);
                    }
                }
            }
        }
        
        return min_distance;
    }
};
