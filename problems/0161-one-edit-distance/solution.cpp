class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        /*
        Problem: 0161 - One Edit Distance
        
        Given two strings s and t, determine if they are exactly one edit distance apart.
        Three possible operations: insert, delete, or replace a character.
        
        Approach:
        - First check if the length difference is valid (at most 1)
        - Compare characters from left to right until we find a mismatch
        - When we find the first mismatch, check if remaining parts can be made equal
        - For same length: skip current char in both and compare rest (replace)
        - For different length: skip char in longer string and compare rest (insert/delete)
        
        Time complexity: O(n).
        Space complexity: O(1).
        */
        
        int len_s = s.length(), len_t = t.length();
        
        // If length difference is more than 1, impossible to be one edit apart.
        if (abs(len_s - len_t) > 1) {
            return false;
        }
        
        // Ensure s is the shorter string for easier processing.
        if (len_s > len_t) {
            return isOneEditDistance(t, s);
        }
        
        // Iterate through both strings to find the first mismatch.
        for (int i = 0; i < len_s; i++) {
            if (s[i] != t[i]) {
                // Found first mismatch position.
                if (len_s == len_t) {
                    // Same length: replace operation - check if rest are equal.
                    return s.substr(i + 1) == t.substr(i + 1);
                } else {
                    // Different length: insert operation - skip char in longer string.
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }
        
        // No mismatch found, check if exactly one character difference.
        return len_t == len_s + 1;
    }
};
