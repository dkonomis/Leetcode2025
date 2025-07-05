class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        """
        Problem: 0010 - Regular Expression Matching.

        Determines whether the input string `s` matches the pattern `p`,
        where:
            - `.` matches any single character.
            - `*` matches zero or more of the preceding character.

        The matching must cover the entire string `s`, not just a substring.

        Approach:
        We use bottom-up dynamic programming. Let dp[i][j] be True if s[i:] matches p[j:].

        Time Complexity: O(m * n), where m = len(s), n = len(p).
        Space Complexity: O(m * n).
        """

        m = len(s)
        n = len(p)

        # dp[i][j] means: does s[i:] match p[j:]?
        dp = [[False] * (n + 1) for _ in range(m + 1)]

        # Base case: both s and p are empty.
        dp[m][n] = True

        # Fill the table in reverse order.
        for i in range(m, -1, -1):
            for j in range(n - 1, -1, -1):

                # Check if the first characters match (if in bounds),
                # or if pattern has a '.' wildcard.
                first_match = i < m and (p[j] == s[i] or p[j] == '.')

                # Handle the '*' operator, which applies to p[j + 1].
                if j + 1 < n and p[j + 1] == '*':
                    # Case 1: '*' represents zero occurrences of p[j].
                    # We skip over the 'x*' (move two steps in pattern).
                    zero_occurrence = dp[i][j + 2]

                    # Case 2: '*' represents one or more of p[j].
                    # Only possible if s[i] matches p[j]; then consume s[i] and stay at p[j].
                    one_or_more = first_match and dp[i + 1][j]

                    dp[i][j] = zero_occurrence or one_or_more

                else:
                    # No '*': just require current characters to match and recurse.
                    dp[i][j] = first_match and dp[i + 1][j + 1]

        # Final result: does s[0:] match p[0:]?
        return dp[0][0]

