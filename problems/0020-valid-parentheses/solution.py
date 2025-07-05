class Solution:
    def isValid(self, s: str) -> bool:
        """
        Problem 0020 – Valid Parentheses.

        Use a stack to store opening brackets.
        For each closing bracket, check if it matches the top of the stack.
        If not, the string is invalid.
        At the end, the stack should be empty for the string to be valid.

        Time Complexity  : O(n), where n is the length of the string.
        Space Complexity : O(n), for the stack in the worst case.
        """

        # Mapping of closing brackets to their corresponding opening brackets.
        bracket_map = {')': '(', '}': '{', ']': '['}

        # Stack to hold opening brackets.
        stack = []

        for char in s:
            if char in bracket_map:
                # Pop from stack if available, else assign dummy value.
                top_element = stack.pop() if stack else '#'

                # Check for mismatch.
                if bracket_map[char] != top_element:
                    return False
            else:
                # It's an opening bracket, push onto stack.
                stack.append(char)

        # Stack should be empty if all brackets matched properly.
        return not stack

