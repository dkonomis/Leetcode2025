class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
         * Problem: 0242 - Valid Anagram
         * 
         * Check if two strings are anagrams by counting character frequencies.
         * Anagrams must have same length and same character counts.
         * Use hash table to count occurrences of each character.
         * 
         * Time complexity: O(n) where n is the length of the strings.
         * Space complexity: O(1) since we have at most 26 lowercase letters.
         */
        
        // Anagrams must have same length.
        if (s.length() != t.length()) {
            return false;
        }
        
        // Count character frequencies.
        unordered_map<char, int> char_count;
        
        // Increment count for characters in s.
        for (char c : s) {
            char_count[c]++;
        }
        
        // Decrement count for characters in t.
        for (char c : t) {
            if (char_count.find(c) == char_count.end()) {
                // Character in t but not in s.
                return false;
            }
            char_count[c]--;
            if (char_count[c] < 0) {
                // More occurrences in t than in s.
                return false;
            }
        }
        
        // All counts should be zero for valid anagram.
        return true;
    }
};
