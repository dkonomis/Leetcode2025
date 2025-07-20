class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        Problem: 0125 - Valid Palindrome
        
        Check if string is a palindrome after normalization.
        
        Approach:
        1. Use two pointers from start and end of string.
        2. Skip non-alphanumeric characters on-the-fly.
        3. Compare characters in lowercase.
        4. Move pointers toward center until they meet.
        
        Time complexity: O(n) where n is length of string.
        Space complexity: O(1) using only constant extra space.
        """
        left, right = 0, len(s) - 1
        
        while left < right:
            # Skip non-alphanumeric characters from left.
            while left < right and not s[left].isalnum():
                left += 1
            
            # Skip non-alphanumeric characters from right.
            while left < right and not s[right].isalnum():
                right -= 1
            
            # Compare characters in lowercase.
            if s[left].lower() != s[right].lower():
                return False
            
            # Move pointers toward center.
            left += 1
            right -= 1
        
        return True
