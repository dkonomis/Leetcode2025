class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        /**
         * Problem: 0159 - Longest Substring with At Most Two Distinct Characters
         * 
         * Find length of longest substring with at most 2 distinct characters.
         * 
         * Approach:
         * Sliding window with hashmap to track character counts.
         * Expand window by moving right pointer.
         * When we have > 2 distinct chars, shrink from left until valid.
         * 
         * Time complexity: O(n).
         * Space complexity: O(1) - at most 3 chars in hashmap.
         */
        
        if (s.length() <= 2) {
            return s.length();
        }
        
        // Sliding window boundaries.
        int left = 0;
        int res = 0;
        
        // Count of each character in current window.
        unordered_map<char, int> char_count;
        
        for (int right = 0; right < s.length(); right++) {
            // Add right character to window.
            char c = s[right];
            char_count[c]++;
            
            // If window has > 2 distinct chars, shrink from left.
            while (char_count.size() > 2) {
                char left_char = s[left];
                char_count[left_char]--;
                
                // Remove character if count reaches 0.
                if (char_count[left_char] == 0) {
                    char_count.erase(left_char);
                }
                
                left++;
            }
            
            // Update max length of valid window.
            res = max(res, right - left + 1);
        }
        
        return res;
    }
};
