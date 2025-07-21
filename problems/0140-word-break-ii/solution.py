class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        """
        Problem: 0140 - Word Break II
        
        Return all possible sentences formed by segmenting string with dictionary words.
        
        Approach:
        1. Use classic backtracking to explore all possible word combinations.
        2. Build path incrementally and backtrack by removing last word.
        3. Join path to form complete sentence when reaching end.
        
        Time complexity: O(2^n * n) in worst case where n is string length.
        Space complexity: O(2^n * n) for storing all possible sentences.
        """
        word_set = set(wordDict)
        res = []
        
        def backtrack(start: int, path: List[str]) -> None:
            # Base case: reached end of string.
            if start == len(s):
                res.append(" ".join(path))
                return
            
            # Try all possible words starting from current position.
            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                
                # If current word is in dictionary, continue backtracking.
                if word in word_set:
                    # Choose.
                    path.append(word)
                    # Explore.
                    backtrack(end, path)
                    # Unchoose (backtrack).
                    path.pop()
        
        backtrack(0, [])
        return res
