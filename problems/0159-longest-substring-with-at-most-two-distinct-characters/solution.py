class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        """
        Problem: 0159 - Longest Substring with At Most Two Distinct Characters
        
        Find length of longest substring with at most 2 distinct characters.
        
        Approach:
        Sliding window with hashmap to track character counts.
        Expand window by moving right pointer.
        When we have > 2 distinct chars, shrink from left until valid.
        
        Time complexity: O(n).
        Space complexity: O(1) - at most 3 chars in hashmap.
        """
        if len(s) <= 2:
            return len(s)
        
        # Sliding window boundaries.
        left = 0
        res = 0
        
        # Count of each character in current window.
        char_count = {}
        
        for right in range(len(s)):
            # Add right character to window.
            char = s[right]
            char_count[char] = char_count.get(char, 0) + 1
            
            # If window has > 2 distinct chars, shrink from left.
            while len(char_count) > 2:
                left_char = s[left]
                char_count[left_char] -= 1
                
                # Remove character if count reaches 0.
                if char_count[left_char] == 0:
                    del char_count[left_char]
                
                left += 1
            
            # Update max length of valid window.
            res = max(res, right - left + 1)
        
        return res
