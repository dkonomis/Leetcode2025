class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        /*
        Problem: 0174 - Dungeon Game
        
        Find minimum initial health for knight to rescue princess.
        Must work backwards from destination since future cells affect current decisions.
        
        Approach:
        - Use reverse DP: start from princess and work backwards to knight
        - dp[i][j] = minimum health needed when entering cell (i,j) to reach princess
        - At each cell, consider paths going down and right
        - Health must always stay >= 1 (never drop to 0 or below)
        - Formula: dp[i][j] = max(1, min(down_health, right_health) - dungeon[i][j])
        
        Time complexity: O(m × n).
        Space complexity: O(m × n).
        */
        
        int m = dungeon.size(), n = dungeon[0].size();
        
        // Create DP table with padding for easier boundary handling.
        // Initialize with large values except for base cases.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        
        // Base cases: positions adjacent to princess need 1 health.
        dp[m][n - 1] = dp[m - 1][n] = 1;
        
        // Work backwards from bottom-right to top-left.
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Get minimum health needed from paths going down and right.
                int down_health = dp[i + 1][j];    // Health needed if going down.
                int right_health = dp[i][j + 1];   // Health needed if going right.
                
                // Choose the path requiring less health.
                int min_health_needed = min(down_health, right_health);
                
                // Calculate required health before entering current cell.
                // Must account for current cell's effect and ensure health >= 1.
                dp[i][j] = max(1, min_health_needed - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};
