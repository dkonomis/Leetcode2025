import math

class Solution:
    def numSquares(self, n: int) -> int:
        """
        Problem: 0279 - Perfect Squares
        
        Find the least number of perfect square numbers that sum to n.
        Pre-compute all perfect squares up to n, then use DP where
        dp[i] = minimum perfect squares needed to sum to i.
        
        Time complexity: O(n * sqrt(n)).
        Space complexity: O(n).
        """
        # Pre-compute all relevant perfect squares.
        square_nums = [i**2 for i in range(1, int(math.sqrt(n)) + 1)]
        
        # DP array where dp[i] = min perfect squares summing to i.
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        
        # Build up solutions for all numbers 1 to n.
        for i in range(1, n + 1):
            for square in square_nums:
                if i < square:
                    break  # All remaining squares are too large.
                dp[i] = min(dp[i], dp[i - square] + 1)
        
        res = dp[-1]
        return res
