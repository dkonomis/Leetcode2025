class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        """
        Problem: 0266 - Palindrome Permutation
        
        Determine if any permutation of the string can form a palindrome.
        
        Approach: Count character frequencies. A palindrome can have at most one character
        with odd frequency (which would be in the center). All other characters must appear
        an even number of times to be mirrored around the center.
        
        Time complexity: O(n) where n is the length of the string.
        Space complexity: O(k) where k is the size of the character set (26 for lowercase letters).
        """
        # Count frequency of each character.
        char_count = {}
        for c in s:
            char_count[c] = char_count.get(c, 0) + 1
        
        # Count characters with odd frequency.
        odd_count = 0
        for count in char_count.values():
            if count % 2 == 1:
                odd_count += 1
        
        # At most one character can have odd frequency.
        return odd_count <= 1
