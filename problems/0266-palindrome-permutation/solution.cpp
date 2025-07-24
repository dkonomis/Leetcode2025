class Solution {
public:
    bool canPermutePalindrome(string s) {
        /**
         * Problem: 0266 - Palindrome Permutation
         * 
         * Determine if any permutation of the string can form a palindrome.
         * 
         * Approach: Count character frequencies. A palindrome can have at most one character
         * with odd frequency (which would be in the center). All other characters must appear
         * an even number of times to be mirrored around the center.
         * 
         * Time complexity: O(n) where n is the length of the string.
         * Space complexity: O(k) where k is the size of the character set (26 for lowercase letters).
         */
        
        // Count frequency of each character.
        unordered_map<char, int> char_count;
        for (char c : s) {
            char_count[c]++;
        }
        
        // Count characters with odd frequency.
        int odd_count = 0;
        for (auto& pair : char_count) {
            if (pair.second % 2 == 1) {
                odd_count++;
            }
        }
        
        // At most one character can have odd frequency.
        return odd_count <= 1;
    }
};
