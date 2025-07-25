class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        """
        Problem: 0291 - Word Pattern II
        
        Check if string s can be segmented to match the pattern where each
        character in pattern maps to a substring in s with bijection.
        Uses backtracking to try all possible segmentations.
        
        Approach:
        - Use DFS with backtracking to try all substring mappings
        - Maintain char->substring and substring->char mappings
        - For each pattern char, try all possible substring lengths
        - Backtrack if mapping leads to contradiction
        
        Time complexity: O(n^m) worst case where n = len(s), m = len(pattern).
        Space complexity: O(m) for recursion stack and mappings.
        """
        def backtrack(p_idx, s_idx):
            # Base case: both pattern and string are fully matched.
            if p_idx == len(pattern) and s_idx == len(s):
                return True
            
            # One finished but not the other.
            if p_idx == len(pattern) or s_idx == len(s):
                return False
            
            # Current pattern character.
            char = pattern[p_idx]
            
            # If char already has a mapping, verify it matches.
            if char in char_to_str:
                mapped_str = char_to_str[char]
                # Check if s has enough chars and matches the mapping.
                if (s_idx + len(mapped_str) <= len(s) and 
                    s[s_idx:s_idx + len(mapped_str)] == mapped_str):
                    return backtrack(p_idx + 1, s_idx + len(mapped_str))
                return False
            
            # Try all possible substrings for this char.
            for end in range(s_idx + 1, len(s) + 1):
                substring = s[s_idx:end]
                
                # Skip if substring already mapped to another char.
                if substring in str_to_char:
                    continue
                
                # Create new mapping.
                char_to_str[char] = substring
                str_to_char[substring] = char
                
                # Recurse with this mapping.
                if backtrack(p_idx + 1, end):
                    return True
                
                # Backtrack: remove mapping.
                del char_to_str[char]
                del str_to_char[substring]
            
            return False
        
        # Mappings for bijection.
        char_to_str = {}
        str_to_char = {}
        
        return backtrack(0, 0)
