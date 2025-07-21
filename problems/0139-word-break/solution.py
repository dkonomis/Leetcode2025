class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        """
        Problem: 0139 - Word Break
        
        Check if string can be segmented into dictionary words.
        
        Approach:
        1. Use DP where dp[i] = can break s[0:i] using dictionary words.
        2. For each position i, try all possible last words ending at i.
        3. dp[i] = True if exists j where dp[j] = True and s[j:i] in wordDict.
        4. Base case: dp[0] = True (empty string).
        
        Time complexity: O(n^2 * m) where n is string length and m is average word length.
        Space complexity: O(n) for the DP array.
        """
        n = len(s)
        word_set = set(wordDict)  # O(1) lookup for words.
        
        # dp[i] = True if s[0:i] can be broken into dictionary words.
        dp = [False] * (n + 1)
        dp[0] = True  # Empty string can always be broken.
        
        for i in range(1, n + 1):
            # Try all possible last words ending at position i.
            for j in range(i):
                # Check if prefix s[0:j] can be broken and s[j:i] is valid word.
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break  # Found one valid segmentation, no need to continue.
        
        return dp[n]
