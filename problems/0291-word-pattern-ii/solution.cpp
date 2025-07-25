class Solution {
private:
    unordered_map<char, string> char_to_str;
    unordered_map<string, char> str_to_char;
    
    bool backtrack(const string& pattern, int p_idx, const string& s, int s_idx) {
        // Base case: both pattern and string are fully matched.
        if (p_idx == pattern.length() && s_idx == s.length()) {
            return true;
        }
        
        // One finished but not the other.
        if (p_idx == pattern.length() || s_idx == s.length()) {
            return false;
        }
        
        // Current pattern character.
        char c = pattern[p_idx];
        
        // If char already has a mapping, verify it matches.
        if (char_to_str.find(c) != char_to_str.end()) {
            string mapped_str = char_to_str[c];
            // Check if s has enough chars and matches the mapping.
            if (s_idx + mapped_str.length() <= s.length() && 
                s.substr(s_idx, mapped_str.length()) == mapped_str) {
                return backtrack(pattern, p_idx + 1, s, s_idx + mapped_str.length());
            }
            return false;
        }
        
        // Try all possible substrings for this char.
        for (int end = s_idx + 1; end <= s.length(); end++) {
            string substring = s.substr(s_idx, end - s_idx);
            
            // Skip if substring already mapped to another char.
            if (str_to_char.find(substring) != str_to_char.end()) {
                continue;
            }
            
            // Create new mapping.
            char_to_str[c] = substring;
            str_to_char[substring] = c;
            
            // Recurse with this mapping.
            if (backtrack(pattern, p_idx + 1, s, end)) {
                return true;
            }
            
            // Backtrack: remove mapping.
            char_to_str.erase(c);
            str_to_char.erase(substring);
        }
        
        return false;
    }
    
public:
    bool wordPatternMatch(string pattern, string s) {
        /**
         * Problem: 0291 - Word Pattern II
         * 
         * Check if string s can be segmented to match the pattern where each
         * character in pattern maps to a substring in s with bijection.
         * Uses backtracking to try all possible segmentations.
         * 
         * Approach:
         * - Use DFS with backtracking to try all substring mappings
         * - Maintain char->substring and substring->char mappings
         * - For each pattern char, try all possible substring lengths
         * - Backtrack if mapping leads to contradiction
         * 
         * Time complexity: O(n^m) worst case where n = len(s), m = len(pattern).
         * Space complexity: O(m) for recursion stack and mappings.
         */
        return backtrack(pattern, 0, s, 0);
    }
};
