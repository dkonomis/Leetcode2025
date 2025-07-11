class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        """
        Problem: 0097 - Interleaving String

        Given strings s1, s2, and s3, determine if s3 is formed by an interleaving of s1 and s2.
        An interleaving keeps the relative order of characters from each input string.

        Approach:
        - Use 2D dynamic programming.
        - Let dp[i][j] be True if s3[:i+j] can be formed by interleaving s1[:i] and s2[:j].
        - Initialize dp[0][0] = True as the empty prefix base case.
        - Fill the table row by row:
            - dp[i][j] is True if:
                - (dp[i-1][j] is True and s1[i-1] == s3[i+j-1]), or
                - (dp[i][j-1] is True and s2[j-1] == s3[i+j-1]).

        Time complexity: O(m * n), where m = len(s1), n = len(s2).
        Space complexity: O(m * n).
        """
        m, n = len(s1), len(s2)

        # If lengths don't match, s3 can't be an interleaving.
        if m + n != len(s3):
            return False

        # Initialize DP table with False.
        dp = [[False] * (n + 1) for _ in range(m + 1)]

        # Base case: empty strings interleave to form empty string.
        dp[0][0] = True

        # Initialize first column (only s1 used).
        for i in range(1, m + 1):
            if s1[i - 1] == s3[i - 1]:
                dp[i][0] = dp[i - 1][0]

        # Initialize first row (only s2 used).
        for j in range(1, n + 1):
            if s2[j - 1] == s3[j - 1]:
                dp[0][j] = dp[0][j - 1]

        # Fill the DP table.
        for i in range(1, m + 1):
            for j in range(1, n + 1):

