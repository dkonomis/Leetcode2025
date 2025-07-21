class Solution {
public:
    int minCut(string s) {
        /*
        Problem: 0132 - Palindrome Partitioning II
        
        Find minimum cuts needed for palindrome partitioning of string s.
        
        Approach:
        1. Use 2D DP to precompute which substrings are palindromes.
        2. Use 1D DP to find minimum cuts for each prefix.
        3. For each position, try all possible last palindromic substrings.
        4. dp[i] = minimum cuts needed for s[0:i+1].
        
        Time complexity: O(n^2) where n is length of string.
        Space complexity: O(n^2) for palindrome table and O(n) for cuts array.
        */
        
        int n = s.length();
        if (n <= 1) {
            return 0;
        }
        
        // Build palindrome table: is_palindrome[i][j] = true if s[i:j+1] is palindrome.
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
        
        // Every single character is palindrome.
        for (int i = 0; i < n; i++) {
            is_palindrome[i][i] = true;
        }
        
        // Check for palindromes of length 2.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                is_palindrome[i][i + 1] = true;
            }
        }
        
        // Check for palindromes of length 3 and more.
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                if (s[i] == s[j] && is_palindrome[i + 1][j - 1]) {
                    is_palindrome[i][j] = true;
                }
            }
        }
        
        // DP to find minimum cuts: dp[i] = min cuts needed for s[0:i+1].
        vector<int> dp(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            // If entire prefix is palindrome, no cuts needed.
            if (is_palindrome[0][i]) {
                dp[i] = 0;
            } else {
                // Try all possible last palindromic substrings ending at i.
                for (int j = 1; j <= i; j++) {
                    if (is_palindrome[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
