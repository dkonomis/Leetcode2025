class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Problem: 0123 - Best Time to Buy and Sell Stock III
        
        Find maximum profit from at most two transactions.
        
        Approach:
        1. Use left-right DP to split the problem.
        2. left[i] = max profit from at most 1 transaction in prices[0:i+1].
        3. right[i] = max profit from at most 1 transaction in prices[i:].
        4. For each split point, combine left[i] + right[i+1].
        
        Time complexity: O(n) where n is length of prices.
        Space complexity: O(n) for the left and right DP arrays.
        """
        if len(prices) <= 1:
            return 0
        
        n = len(prices)
        
        # Build left DP: max profit from at most 1 transaction in prices[0:i+1].
        left = [0] * n
        min_price = prices[0]
        for i in range(1, n):
            min_price = min(min_price, prices[i])
            left[i] = max(left[i - 1], prices[i] - min_price)
        
        # Build right DP: max profit from at most 1 transaction in prices[i:].
        right = [0] * n
        max_price = prices[n - 1]
        for i in range(n - 2, -1, -1):
            max_price = max(max_price, prices[i])
            right[i] = max(right[i + 1], max_price - prices[i])
        
        # Find maximum profit by combining left and right.
        max_profit = 0
        for i in range(n - 1):
            max_profit = max(max_profit, left[i] + right[i + 1])
        
        # Also consider using only one transaction (all in left or all in right).
        max_profit = max(max_profit, left[n - 1], right[0])
        
        return max_profit
