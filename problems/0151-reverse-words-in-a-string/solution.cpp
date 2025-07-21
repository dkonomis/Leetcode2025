class Solution {
public:
    string reverseWords(string s) {
        /**
         * Problem: 0151 - Reverse Words in a String
         * 
         * Reverse the order of words in a string. Handle multiple spaces
         * and leading/trailing spaces.
         * 
         * Approach:
         * Use deque (double-ended queue) to build result efficiently.
         * Parse words with two pointers and add to front of deque.
         * This naturally reverses the order.
         * 
         * Time complexity: O(n).
         * Space complexity: O(n) for the deque and result.
         */
        
        deque<string> res;
        int left = 0;
        int n = s.length();
        
        while (left < n) {
            // Skip spaces.
            while (left < n && s[left] == ' ') {
                left++;
            }
            
            if (left >= n) {
                break;
            }
            
            // Find end of current word.
            int right = left;
            while (right < n && s[right] != ' ') {
                right++;
            }
            
            // Add word to front of deque - this reverses order.
            string word = s.substr(left, right - left);
            if (!res.empty()) {
                // If not first word, add space before it.
                res.push_front(" ");
            }
            res.push_front(word);
            
            // Move to next word.
            left = right;
        }
        
        // Join deque elements into final string.
        string rev = "";
        for (const string& str : res) {
            rev += str;
        }
        
        return rev;
    }
};
