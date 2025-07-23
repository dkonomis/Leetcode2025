class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        """
        Problem: 0188 - Best Time to Buy and Sell Stock IV
        
        Find maximum profit with at most k transactions.
        A transaction is a buy followed by a sell.
        
        Approach:
        - Use dynamic programming with states for holding/not holding stock
        - buy[i] = max profit after at most i buys
        - sell[i] = max profit after at most i complete transactions
        - Special case: if k >= n/2, it's unlimited transactions
        
        Time complexity: O(n * k) where n is the number of days.
        Space complexity: O(k) for the DP arrays.
        """
        if not prices or k == 0:
            return 0
        
        n = len(prices)
        
        # If k >= n/2, we can do as many transactions as we want.
        # This is the same as problem 122 (unlimited transactions).
        if k >= n // 2:
            res = 0
            for i in range(1, n):
                if prices[i] > prices[i-1]:
                    res += prices[i] - prices[i-1]
            return res
        
        # DP arrays for tracking profit after buying and selling.
        buy = [-prices[0]] * (k + 1)  # Max profit after buying.
        sell = [0] * (k + 1)  # Max profit after selling.
        
        for i in range(1, n):
            # Process transactions in reverse to avoid overwriting.
            for j in range(k, 0, -1):
                # Update sell[j]: either keep previous or sell today.
                sell[j] = max(sell[j], buy[j] + prices[i])
                # Update buy[j]: either keep previous or buy today.
                buy[j] = max(buy[j], sell[j-1] - prices[i])
        
        return sell[k]
