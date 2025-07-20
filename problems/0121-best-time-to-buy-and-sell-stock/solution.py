class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Problem: 0121 - Best Time to Buy and Sell Stock
        
        Find maximum profit from buying and selling stock once.
        
        Approach:
        1. Track the minimum price seen so far (best day to buy).
        2. For each day, calculate profit if we sell today.
        3. Keep track of maximum profit achieved.
        4. Single pass through the array.
        
        Time complexity: O(n) where n is length of prices.
        Space complexity: O(1) using only constant extra space.
        """
        if not prices:
            return 0
        
        min_price = prices[0]
        max_profit = 0
        
        for price in prices:
            # Update minimum price if current price is lower.
            min_price = min(min_price, price)
            
            # Calculate profit if we sell today.
            profit = price - min_price
            
            # Update maximum profit if current profit is higher.
            max_profit = max(max_profit, profit)
        
        return max_profit
