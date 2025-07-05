class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        Problem: 0005 - Longest Palindromic Substring.

        Approach:
        - Use dynamic programming to fill a table where dp[left][right] is True if s[left:right+1] is a palindrome.
        - Initialize all single-character and two-character substrings.
        - Expand to longer substrings from the bottom up.

        Time Complexity: O(n^2), where n is the length of the string.
        Space Complexity: O(n^2), for the dp table.
        """

        n = len(s)
        if n == 0:
            return ""

        # Initialize the DP table.
        dp = [[False for right in range(n)] for left in range(n)]

        # Mark all single-character substrings as palindromes.
        for left in range(n):
            dp[left][left] = True
            if left != n - 1:
                dp[left][left + 1] = (s[left] == s[left + 1])

        # Fill the table for substrings of length ≥ 3.
        for left in range(n - 3, -1, -1):
            for right in range(left + 2, n):
                dp[left][right] = dp[left + 1][right - 1] and s[left] == s[right]

        # Find the longest palindromic substring.
        max_length = 0
        res = ""
        for left in range(n):
            for right in range(left, n):
                if dp[left][right] and (right - left + 1) > max_length:
                    max_length = right - left + 1
                    res = s[left:right + 1]

        return res

