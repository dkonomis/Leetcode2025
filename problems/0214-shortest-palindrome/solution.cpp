class Solution {
public:
    string shortestPalindrome(string s) {
        /**
         * Problem: 0214 - Shortest Palindrome
         * 
         * Find the shortest palindrome by adding characters in front of the string.
         * We use KMP algorithm to find the longest palindromic prefix efficiently.
         * Create a combined string: s + '#' + reverse(s), then build LPS array.
         * The last LPS value tells us the longest prefix that is also a palindrome.
         * 
         * Time complexity: O(n) where n is the length of the string.
         * Space complexity: O(n) for the combined string and LPS array.
         */
        
        int n = s.length();
        
        // Empty string is already a palindrome.
        if (n == 0) {
            return s;
        }
        
        // Create combined string with separator to avoid false matches.
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + '#' + rev_s;
        
        // Build LPS (Longest Proper Prefix which is also Suffix) array.
        vector<int> lps = buildLPS(combined);
        
        // Length of longest palindromic prefix.
        int longest_palindrome_prefix = lps.back();
        
        // Add reverse of remaining suffix to the front.
        string remaining = s.substr(longest_palindrome_prefix);
        reverse(remaining.begin(), remaining.end());
        string res = remaining + s;
        
        return res;
    }
    
private:
    vector<int> buildLPS(const string& pattern) {
        // Build the LPS array for KMP algorithm.
        int m = pattern.length();
        vector<int> lps(m, 0);
        int length = 0;  // Length of previous longest prefix suffix.
        int i = 1;
        
        // Build LPS array.
        while (i < m) {
            if (pattern[i] == pattern[length]) {
                // Characters match, extend the prefix.
                length++;
                lps[i] = length;
                i++;
            } else {
                // Characters don't match.
                if (length != 0) {
                    // Try the previous longest prefix suffix.
                    length = lps[length - 1];
                } else {
                    // No proper prefix, move to next character.
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
};
