class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        /**
         * Problem: 0188 - Best Time to Buy and Sell Stock IV
         * 
         * Find maximum profit with at most k transactions.
         * A transaction is a buy followed by a sell.
         * 
         * Approach:
         * - Use dynamic programming with states for holding/not holding stock
         * - buy[i] = max profit after at most i buys
         * - sell[i] = max profit after at most i complete transactions
         * - Special case: if k >= n/2, it's unlimited transactions
         * 
         * Time complexity: O(n * k) where n is the number of days.
         * Space complexity: O(k) for the DP arrays.
         */
        
        if (prices.empty() || k == 0) {
            return 0;
        }
        
        int n = prices.size();
        
        // If k >= n/2, we can do as many transactions as we want.
        // This is the same as problem 122 (unlimited transactions).
        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) {
                    res += prices[i] - prices[i-1];
                }
            }
            return res;
        }
        
        // DP arrays for tracking profit after buying and selling.
        vector<int> buy(k + 1, -prices[0]);   // Max profit after buying.
        vector<int> sell(k + 1, 0);           // Max profit after selling.
        
        for (int i = 1; i < n; i++) {
            // Process transactions in reverse to avoid overwriting.
            for (int j = k; j > 0; j--) {
                // Update sell[j]: either keep previous or sell today.
                sell[j] = max(sell[j], buy[j] + prices[i]);
                // Update buy[j]: either keep previous or buy today.
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
            }
        }
        
        return sell[k];
    }
};
