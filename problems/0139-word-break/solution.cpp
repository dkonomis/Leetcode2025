class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        Problem: 0139 - Word Break
        
        Check if string can be segmented into dictionary words.
        
        Approach:
        1. Use DP where dp[i] = can break s[0:i] using dictionary words.
        2. For each position i, try all possible last words ending at i.
        3. dp[i] = true if exists j where dp[j] = true and s[j:i] in wordDict.
        4. Base case: dp[0] = true (empty string).
        
        Time complexity: O(n^2 * m) where n is string length and m is average word length.
        Space complexity: O(n) for the DP array.
        */
        
        int n = s.length();
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());  // O(1) lookup for words.
        
        // dp[i] = true if s[0:i] can be broken into dictionary words.
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string can always be broken.
        
        for (int i = 1; i <= n; i++) {
            // Try all possible last words ending at position i.
            for (int j = 0; j < i; j++) {
                // Check if prefix s[0:j] can be broken and s[j:i] is valid word.
                if (dp[j] && word_set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // Found one valid segmentation, no need to continue.
                }
            }
        }
        
        return dp[n];
    }
};
