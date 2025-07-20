class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*
        Problem: 0120 - Triangle
        
        Find the minimum path sum from top to bottom of triangle.
        
        Approach:
        1. Use bottom-up DP starting from the bottom row.
        2. For each position, take minimum of two possible paths from row below.
        3. Space-optimized: use only one array representing current minimum sums.
        4. Work upward until we reach the top.
        
        Time complexity: O(n^2) where n is number of rows.
        Space complexity: O(n) for the DP array.
        */
        
        int n = triangle.size();
        
        // Start with the bottom row as initial DP state.
        vector<int> dp = triangle[n - 1];
        
        // Work from second-to-last row up to the top.
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < triangle[row].size(); col++) {
                // Take minimum of two adjacent paths from row below.
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        
        // The top element contains the minimum path sum.
        return dp[0];
    }
};
