class Solution {
public:
    void reverseWords(vector<char>& s) {
        /**
         * Problem: 0186 - Reverse Words in a String II
         * 
         * Reverse the order of words in a character array in-place.
         * Each word is a sequence of non-space characters separated by single spaces.
         * 
         * Approach:
         * - First reverse the entire array to get words in reverse order
         * - Then reverse each individual word to restore correct character order
         * - Use two pointers to identify word boundaries
         * 
         * Time complexity: O(n) where n is the length of the array.
         * Space complexity: O(1) as we modify in-place.
         */
        
        int n = s.size();
        
        // Step 1: Reverse the entire array.
        reverse(s, 0, n - 1);
        
        // Step 2: Reverse each individual word.
        int start = 0;
        for (int i = 0; i < n; i++) {
            // When we hit a space, reverse the current word.
            if (s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
            // Don't forget to reverse the last word.
            else if (i == n - 1) {
                reverse(s, start, i);
            }
        }
    }
    
private:
    void reverse(vector<char>& s, int left, int right) {
        // Helper function to reverse a portion of the array.
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
