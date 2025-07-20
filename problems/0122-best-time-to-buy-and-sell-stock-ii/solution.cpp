class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        Problem: 0122 - Best Time to Buy and Sell Stock II
        
        Find maximum profit from unlimited buy/sell transactions.
        
        Approach:
        1. Capture every positive price movement.
        2. Sum all positive daily price differences.
        3. Equivalent to buying before each price increase and selling before each decrease.
        
        Time complexity: O(n) where n is length of prices.
        Space complexity: O(1) using only constant extra space.
        */
        
        if (prices.size() <= 1) {
            return 0;
        }
        
        int total_profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // If price increased from yesterday, capture the profit.
            if (prices[i] > prices[i - 1]) {
                total_profit += prices[i] - prices[i - 1];
            }
        }
        
        return total_profit;
    }
};
