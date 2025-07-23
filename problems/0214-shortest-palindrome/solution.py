class Solution:
    def shortestPalindrome(self, s: str) -> str:
        """
        Problem: 0214 - Shortest Palindrome
        
        Find the shortest palindrome by adding characters in front of the string.
        We use KMP algorithm to find the longest palindromic prefix efficiently.
        Create a combined string: s + '#' + reverse(s), then build LPS array.
        The last LPS value tells us the longest prefix that is also a palindrome.
        
        Time complexity: O(n) where n is the length of the string.
        Space complexity: O(n) for the combined string and LPS array.
        """
        n = len(s)
        
        # Empty string is already a palindrome.
        if n == 0:
            return s
        
        # Create combined string with separator to avoid false matches.
        rev_s = s[::-1]
        combined = s + '#' + rev_s
        
        # Build LPS (Longest Proper Prefix which is also Suffix) array.
        lps = self.build_lps(combined)
        
        # Length of longest palindromic prefix.
        longest_palindrome_prefix = lps[-1]
        
        # Add reverse of remaining suffix to the front.
        remaining = s[longest_palindrome_prefix:]
        res = remaining[::-1] + s
        
        return res
    
    def build_lps(self, pattern: str) -> List[int]:
        """Build the LPS array for KMP algorithm."""
        m = len(pattern)
        lps = [0] * m
        length = 0  # Length of previous longest prefix suffix.
        i = 1
        
        # Build LPS array.
        while i < m:
            if pattern[i] == pattern[length]:
                # Characters match, extend the prefix.
                length += 1
                lps[i] = length
                i += 1
            else:
                # Characters don't match.
                if length != 0:
                    # Try the previous longest prefix suffix.
                    length = lps[length - 1]
                else:
                    # No proper prefix, move to next character.
                    lps[i] = 0
                    i += 1
        
        return lps
