class Solution:
    def minCut(self, s: str) -> int:
        """
        Problem: 0132 - Palindrome Partitioning II
        
        Find minimum cuts needed for palindrome partitioning of string s.
        
        Approach:
        1. Use 2D DP to precompute which substrings are palindromes.
        2. Use 1D DP to find minimum cuts for each prefix.
        3. For each position, try all possible last palindromic substrings.
        4. dp[i] = minimum cuts needed for s[0:i+1].
        
        Time complexity: O(n^2) where n is length of string.
        Space complexity: O(n^2) for palindrome table and O(n) for cuts array.
        """
        n = len(s)
        if n <= 1:
            return 0
        
        # Build palindrome table: is_palindrome[i][j] = True if s[i:j+1] is palindrome.
        is_palindrome = [[False] * n for _ in range(n)]
        
        # Every single character is palindrome.
        for i in range(n):
            is_palindrome[i][i] = True
        
        # Check for palindromes of length 2.
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                is_palindrome[i][i + 1] = True
        
        # Check for palindromes of length 3 and more.
        for length in range(3, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if s[i] == s[j] and is_palindrome[i + 1][j - 1]:
                    is_palindrome[i][j] = True
        
        # DP to find minimum cuts: dp[i] = min cuts needed for s[0:i+1].
        dp = [float('inf')] * n
        
        for i in range(n):
            # If entire prefix is palindrome, no cuts needed.
            if is_palindrome[0][i]:
                dp[i] = 0
            else:
                # Try all possible last palindromic substrings ending at i.
                for j in range(1, i + 1):
                    if is_palindrome[j][i]:
                        dp[i] = min(dp[i], dp[j - 1] + 1)
        
        return dp[n - 1]
