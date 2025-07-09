class Solution:
    def climbStairs(self, n: int) -> int:
        """
        Problem: 0070 - Climbing Stairs

        You are climbing a staircase. Each time you can climb 1 or 2 steps.
        Return the number of distinct ways to reach the top.

        Approach:
        - This is a Fibonacci problem: ways(n) = ways(n-1) + ways(n-2)
        - Use iteration to build up the solution from the base cases.

        Time complexity: O(n)
        Space complexity: O(1)
        """
        if n <= 2:
            return n  # Base cases: 1 → 1 way, 2 → 2 ways.

        a, b = 1, 2  # Initialize ways(1) = 1, ways(2) = 2

        for _ in range(3, n + 1):
            a, b = b, a + b  # Update to next Fibonacci number.

        return b

