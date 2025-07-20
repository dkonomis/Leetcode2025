class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        Problem: 0123 - Best Time to Buy and Sell Stock III
        
        Find maximum profit from at most two transactions.
        
        Approach:
        1. Use left-right DP to split the problem.
        2. left[i] = max profit from at most 1 transaction in prices[0:i+1].
        3. right[i] = max profit from at most 1 transaction in prices[i:].
        4. For each split point, combine left[i] + right[i+1].
        
        Time complexity: O(n) where n is length of prices.
        Space complexity: O(n) for the left and right DP arrays.
        */
        
        if (prices.size() <= 1) {
            return 0;
        }
        
        int n = prices.size();
        
        // Build left DP: max profit from at most 1 transaction in prices[0:i+1].
        vector<int> left(n, 0);
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            min_price = min(min_price, prices[i]);
            left[i] = max(left[i - 1], prices[i] - min_price);
        }
        
        // Build right DP: max profit from at most 1 transaction in prices[i:].
        vector<int> right(n, 0);
        int max_price = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_price = max(max_price, prices[i]);
            right[i] = max(right[i + 1], max_price - prices[i]);
        }
        
        // Find maximum profit by combining left and right.
        int max_profit = 0;
        for (int i = 0; i < n - 1; i++) {
            max_profit = max(max_profit, left[i] + right[i + 1]);
        }
        
        // Also consider using only one transaction (all in left or all in right).
        max_profit = max(max_profit, left[n - 1]);
        max_profit = max(max_profit, right[0]);
        
        return max_profit;
    }
};
