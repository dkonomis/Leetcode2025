class Solution:
    def myAtoi(self, s: str) -> int:
        """
        Problem: 0008 - String to Integer (atoi).

        Parses a string to return a signed 32-bit integer, emulating C/C++-style atoi behavior.
        Handles whitespace, signs, digit parsing, and overflow/underflow manually.

        Time Complexity: O(n)
        Space Complexity: O(1)
        """

        INT_MAX = 2**31 - 1  # 2147483647
        INT_MIN = -2**31     # -2147483648

        i = 0
        n = len(s)
        res = 0
        sign = 1

        # Step 1: Skip leading whitespaces.
        while i < n and s[i] == ' ':
            i += 1

        # Step 2: Read optional '+' or '-' sign.
        if i < n and (s[i] == '+' or s[i] == '-'):
            sign = -1 if s[i] == '-' else 1
            i += 1

        # Step 3: Read digits and build the number.
        while i < n and s[i].isdigit():
            digit = int(s[i])

            # Step 4: Handle overflow and underflow explicitly.
            if sign == 1:
                if res > INT_MAX // 10 or (res == INT_MAX // 10 and digit > 7):
                    return INT_MAX
            else:
                if res > INT_MAX // 10 or (res == INT_MAX // 10 and digit > 8):
                    return INT_MIN

            res = res * 10 + digit
            i += 1

        return sign * res

