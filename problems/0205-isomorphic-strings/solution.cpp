class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
         * Problem: 0205 - Isomorphic Strings
         * Given two strings s and t, determine if they are isomorphic. Two strings
         * are isomorphic if characters in s can be replaced to get t with one-to-one mapping.
         * 
         * Approach: Use two unordered_maps to track bidirectional mapping. Each character
         * in s must map to exactly one character in t, and vice versa.
         * 
         * Time complexity: O(n) where n is length of strings.
         * Space complexity: O(1) since we have at most 128 ASCII characters.
         */
        
        if (s.length() != t.length()) {
            return false;
        }
        
        // Two maps for bidirectional mapping.
        unordered_map<char, char> s_to_t;  // Maps characters from s to t.
        unordered_map<char, char> t_to_s;  // Maps characters from t to s.
        
        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];
            
            // Check if s[i] already has a mapping.
            if (s_to_t.find(char_s) != s_to_t.end()) {
                if (s_to_t[char_s] != char_t) {
                    return false;  // Inconsistent mapping.
                }
            } else {
                s_to_t[char_s] = char_t;
            }
            
            // Check if t[i] already has a mapping.
            if (t_to_s.find(char_t) != t_to_s.end()) {
                if (t_to_s[char_t] != char_s) {
                    return false;  // Inconsistent mapping.
                }
            } else {
                t_to_s[char_t] = char_s;
            }
        }
        
        return true;
    }
};
