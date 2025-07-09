class Solution:
    def isNumber(self, s: str) -> bool:
        """
        Problem: 0065 - Valid Number

        Given a string s, return whether it represents a valid number.

        Approach:
        - We use a finite state machine by parsing the string character by character.
        - Track whether we've seen a digit, a dot, or an exponent.
        - Handle optional leading '+' or '-' signs.
        - Only allow 'e' or 'E' once and only after a valid number.
        - After an 'e' or 'E', we must see an integer.

        Time complexity: O(n), where n = len(s)
        Space complexity: O(1)
        """
        s = s.strip()  # Remove leading and trailing spaces.

        if not s:
            return False

        seen_digit = False
        seen_dot = False
        seen_exp = False

        for i, char in enumerate(s):
            if char.isdigit():
                seen_digit = True
            elif char in ['+', '-']:
                # Sign is allowed only at the start or just after exponent.
                if i > 0 and s[i - 1] not in ['e', 'E']:
                    return False
            elif char == '.':
                # Dot is allowed only once and not after exponent.
                if seen_dot or seen_exp:
                    return False
                seen_dot = True
            elif char in ['e', 'E']:
                # Exponent is allowed only once and only after a digit.
                if seen_exp or not seen_digit:
                    return False
                seen_exp = True
                seen_digit = False  # Reset seen_digit to ensure digits follow exponent.
            else:
                return False

        return seen_digit

