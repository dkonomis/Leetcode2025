class Solution:
    def isPalindrome(self, x: int) -> bool:
        """
        Problem: 0009 - Palindrome Number.

        Determines whether an integer is a palindrome without converting it to a string.

        Time Complexity: O(log₁₀(n)), since we divide the number by 10 each iteration.
        Space Complexity: O(1).
        """

        # Negative numbers are not palindromes because of the '-' sign.
        if x < 0:
            return False

        # Numbers ending in 0 are not palindromes unless the number is 0 itself.
        if x != 0 and x % 10 == 0:
            return False

        reversed_half = 0

        # Reverse half of the number to compare with the other half.
        while x > reversed_half:
            digit = x % 10
            reversed_half = reversed_half * 10 + digit
            x //= 10

        # Check if the number is a palindrome.
        # For even digit counts, x should equal reversed_half.
        # For odd digit counts, remove the middle digit from reversed_half.
        return x == reversed_half or x == reversed_half // 10

