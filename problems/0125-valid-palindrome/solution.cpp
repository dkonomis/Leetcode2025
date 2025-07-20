class Solution {
public:
    bool isPalindrome(string s) {
        /*
        Problem: 0125 - Valid Palindrome
        
        Check if string is a palindrome after normalization.
        
        Approach:
        1. Use two pointers from start and end of string.
        2. Skip non-alphanumeric characters on-the-fly.
        3. Compare characters in lowercase.
        4. Move pointers toward center until they meet.
        
        Time complexity: O(n) where n is length of string.
        Space complexity: O(1) using only constant extra space.
        */
        
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left.
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right.
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters in lowercase.
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move pointers toward center.
            left++;
            right--;
        }
        
        return true;
    }
};
