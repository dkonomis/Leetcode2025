class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        /**
         * Problem: 0187 - Repeated DNA Sequences
         * 
         * Find all 10-letter-long DNA sequences that occur more than once.
         * DNA consists of nucleotides: A, C, G, T.
         * 
         * Approach:
         * - Use a sliding window of size 10 to check all substrings
         * - Use a hash map to count occurrences of each sequence
         * - Add to result when count becomes exactly 2 (avoid duplicates)
         * 
         * Time complexity: O(n) where n is the length of the string.
         * Space complexity: O(n) for storing sequences in the hash map.
         */
        
        vector<string> res;
        
        // Handle edge case where string is too short.
        if (s.length() < 10) {
            return res;
        }
        
        // Map to count occurrences of each 10-letter sequence.
        unordered_map<string, int> sequence_count;
        
        // Slide through the string with a window of size 10.
        for (int i = 0; i <= s.length() - 10; i++) {
            // Extract the current 10-letter sequence.
            string sequence = s.substr(i, 10);
            
            // Update count in map.
            sequence_count[sequence]++;
            
            // Add to result when we see it exactly twice.
            // This ensures we don't add duplicates to the result.
            if (sequence_count[sequence] == 2) {
                res.push_back(sequence);
            }
        }
        
        return res;
    }
};
