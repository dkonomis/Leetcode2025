class Solution {
public:
    bool isPalindrome(int x) {
        /*
        Problem: 0009 - Palindrome Number.

        Determines whether an integer is a palindrome without converting it to a string.

        Time Complexity: O(log₁₀(n)), since we divide the number by 10 each iteration.
        Space Complexity: O(1).
        */

        // Negative numbers are not palindromes because of the minus sign.
        if (x < 0) {
            return false;
        }

        // Numbers ending in 0 are not palindromes unless the number is 0 itself.
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse half of the number to compare with the other half.
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // For even-length numbers: x should equal reversedHalf.
        // For odd-length numbers: x should equal reversedHalf without its middle digit.
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

