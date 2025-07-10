class Solution:
    def numDecodings(self, s: str) -> int:
        """
        Problem: 0091 - Decode Ways

        Given a string s containing only digits, return the number of ways to decode it
        using the mapping '1' -> 'A' to '26' -> 'Z'. A '0' cannot be decoded alone.

        Approach:
        - Use dynamic programming with constant space.
        - Let two_back be the number of ways to decode up to position i - 2,
          and one_back be the number of ways up to position i - 1.
        - For each character, compute the current number of decodings as follows:
            - If the current character is not '0', add one_back to current (single-digit decode).
            - If the two-digit number formed with the previous character is between 10 and 26,
              add two_back to current (valid two-digit decode).
        - Move the window forward at each step by shifting two_back and one_back.

        Time complexity: O(n)
        Space complexity: O(1)
        """
        two_back, one_back = 0, 1  # two_back = dp[i - 2], one_back = dp[i - 1]

        # Iterate over each character in the input string.
        for i in range(len(s)):
            current = 0
            # Single-digit decode is valid if s[i] != '0'.
            if s[i] != '0':
                current += one_back
            # Two-digit decode is valid if s[i-1:i+1] in [10, 26].
            if i > 0 and s[i - 1] != '0' and 10 <= int(s[i - 1:i + 1]) <= 26:
                current += two_back
            # Move the DP window forward: update two_back and one_back.
            two_back, one_back = one_back, current

        return one_back

