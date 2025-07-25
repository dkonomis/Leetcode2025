class Solution {
public:
    int numSquares(int n) {
        /**
         * Problem: 0279 - Perfect Squares
         * 
         * Find the least number of perfect square numbers that sum to n.
         * Pre-compute all perfect squares up to n, then use DP where
         * dp[i] = minimum perfect squares needed to sum to i.
         * 
         * Time complexity: O(n * sqrt(n)).
         * Space complexity: O(n).
         */
        
        // Pre-compute all relevant perfect squares.
        vector<int> square_nums;
        for (int i = 1; i * i <= n; i++) {
            square_nums.push_back(i * i);
        }
        
        // DP array where dp[i] = min perfect squares summing to i.
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        // Build up solutions for all numbers 1 to n.
        for (int i = 1; i <= n; i++) {
            for (int square : square_nums) {
                if (i < square) {
                    break;  // All remaining squares are too large.
                }
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
        
        int res = dp[n];
        return res;
    }
};
