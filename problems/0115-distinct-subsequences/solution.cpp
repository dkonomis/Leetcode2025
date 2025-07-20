class Solution {
public:
    int numDistinct(string s, string t) {
        /*
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
        */
        
        int m = s.length();
        int n = t.length();
        
        // dp[i][j] = number of ways to form t[j:] using s[i:].
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Base case: empty suffix of t can always be formed.
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        
        // Fill the DP table from bottom-right to top-left.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Early termination: not enough characters left.
                if (m - i < n - j) {
                    dp[i][j] = 0;
                    continue;
                }
                
                // We can always skip the current character in s.
                dp[i][j] = dp[i + 1][j];
                
                // If characters match, we can also use the current character.
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        
        return (int)dp[0][0];
    }
};
