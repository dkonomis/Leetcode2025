class Solution:
    def longestValidParentheses(self, s: str) -> int:
        """
        0032. Longest Valid Parentheses

        Problem:
        Given a string s containing only '(' and ')', return the length of the longest 
        valid (well-formed) parentheses substring.

        Approach:
        Use a stack to track the indices of unmatched parentheses.
        Initialize the stack with -1 to handle edge cases.
        For each '(' push its index.
        For each ')', pop the stack. If the stack is empty after popping, push current index.
        Otherwise, update the max length using the distance between current index and stack top.

        Time complexity: O(n)
        Space complexity: O(n)
        """
        max_len = 0
        stack = [-1]  # Initialize with base index.

        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)  # Push index of '('.
            else:
                stack.pop()  # Try to match with previous '('.
                if not stack:
                    stack.append(i)  # No match found, push index as new base.
                else:
                    max_len = max(max_len, i - stack[-1])  # Update max length.

        return max_len

