class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        """
        Problem: 0087 - Scramble String

        Given two strings s1 and s2, return True if s2 is a scrambled string of s1.
        A scramble means s2 can be formed by recursively swapping substrings of s1.

        Approach:
        - Use recursion to test all possible split points.
        - At each level, check two cases:
            1. No swap: s1[:i] vs s2[:i] and s1[i:] vs s2[i:]
            2. Swap: s1[:i] vs s2[-i:] and s1[i:] vs s2[:-i]
        - Use memoization (lru_cache) to avoid recomputation.
        - Prune early by comparing sorted versions of s1 and s2.

        Time complexity: O(n^4), due to recursive splitting and memoization.
        Space complexity: O(n^3), for memoization cache size and call stack.
        """
        from functools import lru_cache

        @lru_cache(maxsize=None)
        def dfs(a: str, b: str) -> bool:
            if a == b:
                return True

            if sorted(a) != sorted(b):
                return False  # Prune: different character counts.

            n = len(a)
            # Try all possible split points.
            for i in range(1, n):
                # Case 1: No swap.
                if dfs(a[:i], b[:i]) and dfs(a[i:], b[i:]):
                    return True
                # Case 2: Swap.
                if dfs(a[:i], b[-i:]) and dfs(a[i:], b[:-i]):
                    return True

            return False

        return dfs(s1, s2)

