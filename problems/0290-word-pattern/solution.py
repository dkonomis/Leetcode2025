class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        """
        Problem: 0290 - Word Pattern
        
        Check if string s follows the same pattern as the given pattern
        string. Must establish a bijection (one-to-one mapping) between
        pattern characters and words in s.
        
        Approach:
        - Split s into words
        - Use two dictionaries for bidirectional mapping
        - Check both directions: char->word and word->char
        - Any violation of bijection returns False
        
        Time complexity: O(n) where n is length of pattern.
        Space complexity: O(n) for the two dictionaries.
        """
        words = s.split()
        
        # Must have same number of pattern chars and words.
        if len(pattern) != len(words):
            return False
        
        # Two dictionaries for bijection.
        char_to_word = {}
        word_to_char = {}
        
        # Check each character-word pair.
        for char, word in zip(pattern, words):
            # Check char -> word mapping.
            if char in char_to_word:
                if char_to_word[char] != word:
                    return False
            else:
                char_to_word[char] = word
            
            # Check word -> char mapping.
            if word in word_to_char:
                if word_to_char[word] != char:
                    return False
            else:
                word_to_char[word] = char
        
        return True
