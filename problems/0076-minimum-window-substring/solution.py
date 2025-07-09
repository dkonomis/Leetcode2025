from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        """
        Problem: 0076 - Minimum Window Substring

        Given two strings s and t, return the minimum window in s which contains all the characters in t.
        If there is no such window, return the empty string.

        Approach:
        - Use the sliding window technique with two pointers (left, right).
        - Count the frequency of characters needed from t using a hash map.
        - Expand the right pointer to include more characters until the window is valid.
        - Then, move the left pointer to shrink the window while still maintaining validity.
        - Keep track of the minimum valid window seen.

        Time complexity: O(m + n), where m = len(s), n = len(t).
        Space complexity: O(n) for the character counts.
        """
        if not t or not s:
            return ""

        t_count = Counter(t)  # Frequency of required characters.
        window = {}  # Frequency of current window characters.
        have, need = 0, len(t_count)

        res = [-1, -1]  # Start and end of best window.
        res_len = float("inf")
        left = 0

        # Expand the window with the right pointer.
        for right in range(len(s)):
            char = s[right]
            window[char] = window.get(char, 0) + 1

            # Check if this character satisfies one required frequency.
            if char in t_count and window[char] == t_count[char]:
                have += 1

            # Try to contract the window from the left.
            while have == need:
                # Update result if this window is smaller.
                if (right - left + 1) < res_len:
                    res = [left, right]
                    res_len = right - left + 1

                # Remove the leftmost character from the window.
                window[s[left]] -= 1
                if s[left] in t_count and window[s[left]] < t_count[s[left]]:
                    have -= 1  # No longer satisfies required count.
                left += 1  # Shrink the window.

        l, r = res
        return s[l:r+1] if res_len != float("inf") else ""

