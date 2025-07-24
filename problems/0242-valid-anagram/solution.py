class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        """
        Problem: 0242 - Valid Anagram
        
        Check if two strings are anagrams by counting character frequencies.
        Anagrams must have same length and same character counts.
        Use hash table to count occurrences of each character.
        
        Time complexity: O(n) where n is the length of the strings.
        Space complexity: O(1) since we have at most 26 lowercase letters.
        """
        # Anagrams must have same length.
        if len(s) != len(t):
            return False
        
        # Count character frequencies.
        char_count = {}
        
        # Increment count for characters in s.
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # Decrement count for characters in t.
        for char in t:
            if char not in char_count:
                # Character in t but not in s.
                return False
            char_count[char] -= 1
            if char_count[char] < 0:
                # More occurrences in t than in s.
                return False
        
        # All counts should be zero for valid anagram.
        return True
