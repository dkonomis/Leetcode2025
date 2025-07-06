from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        """
        Problem 0022 – Generate Parentheses.

        Given n pairs of parentheses, generate all combinations of well-formed (balanced) parentheses.

        Approach:
        Use backtracking to build valid combinations character by character.
        We keep track of how many opening and closing parentheses are still allowed.
        We mutate a shared path (list of characters) and use append/pop to backtrack.

        Time Complexity  : O(4^n / sqrt(n)), based on Catalan numbers.
        Space Complexity : O(n), maximum recursion depth and space per path.
        """
        answer = []

        def backtrack(path: List[str], open_count: int, close_count: int) -> None:
            # If the path has the right length, record the result.
            if len(path) == 2 * n:
                answer.append("".join(path))
                return

            # Add an open parenthesis if we still can.
            if open_count < n:
                path.append("(")
                backtrack(path, open_count + 1, close_count)
                path.pop()

            # Add a close parenthesis if it won’t unbalance.
            if close_count < open_count:
                path.append(")")
                backtrack(path, open_count, close_count + 1)
                path.pop()

        backtrack([], 0, 0)
        return answer

