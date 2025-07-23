class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        """
        Problem: 0205 - Isomorphic Strings
        
        Given two strings s and t, determine if they are isomorphic. Two strings
        are isomorphic if characters in s can be replaced to get t with one-to-one mapping.
        
        Approach: Use two dictionaries to track bidirectional mapping. Each character
        in s must map to exactly one character in t, and vice versa.
        
        Time complexity: O(n) where n is length of strings.
        Space complexity: O(1) since we have at most 128 ASCII characters.
        """
        if len(s) != len(t):
            return False
        
        # Two dictionaries for bidirectional mapping.
        s_to_t = {}  # Maps characters from s to t.
        t_to_s = {}  # Maps characters from t to s.
        
        for i in range(len(s)):
            char_s, char_t = s[i], t[i]
            
            # Check if s[i] already has a mapping.
            if char_s in s_to_t:
                if s_to_t[char_s] != char_t:
                    return False  # Inconsistent mapping.
            else:
                s_to_t[char_s] = char_t
            
            # Check if t[i] already has a mapping.
            if char_t in t_to_s:
                if t_to_s[char_t] != char_s:
                    return False  # Inconsistent mapping.
            else:
                t_to_s[char_t] = char_s
        
        return True
