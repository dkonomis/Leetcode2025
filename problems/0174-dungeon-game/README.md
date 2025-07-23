class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        """
        0174 - Dungeon Game
        
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
        """
        m, n = len(dungeon), len(dungeon[0])
        
        # Create DP table with padding for easier boundary handling.
        # Initialize with infinity except for base cases.
        dp = [[float('inf')] * (n + 1) for _ in range(m + 1)]
        
        # Base cases: positions adjacent to princess need 1 health.
        dp[m][n - 1] = dp[m - 1][n] = 1
        
        # Work backwards from bottom-right to top-left.
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                # Get minimum health needed from paths going down and right.
                down_health = dp[i + 1][j]    # Health needed if going down.
                right_health = dp[i][j + 1]   # Health needed if going right.
                
                # Choose the path requiring less health.
                min_health_needed = min(down_health, right_health)
                
                # Calculate required health before entering current cell.
                # Must account for current cell's effect and ensure health >= 1.
                dp[i][j] = max(1, min_health_needed - dungeon[i][j])
        
        return dp[0][0]
