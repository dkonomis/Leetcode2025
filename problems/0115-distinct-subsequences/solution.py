class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        """
        Problem: 0115 - Distinct Subsequences
        
        Count the number of distinct subsequences of s that equal t.
        
        Approach:
        1. Convert memoized recursion to bottom-up DP.
        2. dp[i][j] = ways to form t[j:] using s[i:] (suffix-based).
        3. If s[i] == t[j], we can use or skip this character.
        4. If s[i] != t[j], we can only skip this character.
        5. Base cases: dp[i][n] = 1, dp[m][j] = 0 (j < n).
        
        Time complexity: O(m * n) where m is length of s and n is length of t.
        Space complexity: O(m * n) for the DP table.
        """
        m, n = len(s), len(t)
        
        # dp[i][j] = number of ways to form t[j:] using s[i:].
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Base case: empty suffix of t can always be formed.
        for i in range(m + 1):
            dp[i][n] = 1
        
        # Fill the DP table from bottom-right to top-left.
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                # Early termination: not enough characters left.
                if m - i < n - j:
                    dp[i][j] = 0
                    continue
                
                # We can always skip the current character in s.
                dp[i][j] = dp[i + 1][j]
                
                # If characters match, we can also use the current character.
                if s[i] == t[j]:
                    dp[i][j] += dp[i + 1][j + 1]
        
        return dp[0][0]
