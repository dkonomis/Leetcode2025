class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /**
         * Problem: 0290 - Word Pattern
         * 
         * Check if string s follows the same pattern as the given pattern
         * string. Must establish a bijection (one-to-one mapping) between
         * pattern characters and words in s.
         * 
         * Approach:
         * - Split s into words
         * - Use two dictionaries for bidirectional mapping
         * - Check both directions: char->word and word->char
         * - Any violation of bijection returns False
         * 
         * Time complexity: O(n) where n is length of pattern.
         * Space complexity: O(n) for the two dictionaries.
         */
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Split string into words.
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Must have same number of pattern chars and words.
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // Two dictionaries for bijection.
        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;
        
        // Check each character-word pair.
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // Check char -> word mapping.
            if (char_to_word.find(c) != char_to_word.end()) {
                if (char_to_word[c] != w) {
                    return false;
                }
            } else {
                char_to_word[c] = w;
            }
            
            // Check word -> char mapping.
            if (word_to_char.find(w) != word_to_char.end()) {
                if (word_to_char[w] != c) {
                    return false;
                }
            } else {
                word_to_char[w] = c;
            }
        }
        
        return true;
    }
};
