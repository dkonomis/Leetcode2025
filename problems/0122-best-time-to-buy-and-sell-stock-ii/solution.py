class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Problem: 0122 - Best Time to Buy and Sell Stock II
        
        Find maximum profit from unlimited buy/sell transactions.
        
        Approach:
        1. Capture every positive price movement.
        2. Sum all positive daily price differences.
        3. Equivalent to buying before each price increase and selling before each decrease.
        
        Time complexity: O(n) where n is length of prices.
        Space complexity: O(1) using only constant extra space.
        """
        if len(prices) <= 1:
            return 0
        
        total_profit = 0
        
        for i in range(1, len(prices)):
            # If price increased from yesterday, capture the profit.
            if prices[i] > prices[i - 1]:
                total_profit += prices[i] - prices[i - 1]
        
        return total_profit
