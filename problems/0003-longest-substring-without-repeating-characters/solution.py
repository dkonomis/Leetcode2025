class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Problem: 0003 - Longest Substring Without Repeating Characters.

        Given a string, find the length of the longest substring without repeating characters.

        Approach:
        - Use a sliding window (left and right pointers).
        - Expand the right pointer to include new characters.
        - If a duplicate is found, move the left pointer forward
          until the window contains only unique characters again.
        - Track the maximum window size during traversal.

        Time Complexity: O(n), where n is the length of the string.
        Space Complexity: O(min(n, m)), where m is the charset size (e.g., 128).
        """

        seen = set()        # Characters currently in the window.
        left = 0            # Left boundary of the window.
        max_len = 0         # Length of the longest valid window found.

        for right in range(len(s)):
            # Shrink the window from the left while s[right] is a duplicate.
            while s[right] in seen:
                seen.remove(s[left])    # Remove the leftmost character.
                left += 1               # Move the left boundary forward.

            seen.add(s[right])          # Add current character to the set.
            max_len = max(max_len, right - left + 1)  # Update max length.

        return max_len
