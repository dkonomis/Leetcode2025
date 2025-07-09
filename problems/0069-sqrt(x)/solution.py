class Solution:
    def mySqrt(self, x: int) -> int:
        """
        Problem: 0069 - Sqrt(x)

        Given a non-negative integer x, compute and return the square root of x,
        rounded down to the nearest integer.

        Approach:
        - Use binary search to find the largest integer whose square is ≤ x.
        - Search range is from 0 to x.
        - If mid² ≤ x but (mid + 1)² > x, we've found the answer.

        Time complexity: O(log x)
        Space complexity: O(1)
        """
        if x < 2:
            return x  # Quick return for 0 or 1.

        left, right = 1, x

        # Perform binary search for the square root.
        while left <= right:
            mid = (left + right) // 2
            squared = mid * mid

            if squared == x:
                return mid  # Perfect square found.
            elif squared < x:
                left = mid + 1  # Try a larger candidate.
            else:
                right = mid - 1  # Try a smaller candidate.

        # Right is the floor of sqrt(x) when loop ends.
        return right

