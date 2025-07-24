class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        /**
         * Problem: 0256 - Paint House
         * 
         * Dynamic programming approach tracking minimum cost to paint houses
         * ending with each color. For each house, calculate the minimum cost
         * to paint it each color based on previous house's different colors.
         * 
         * Time complexity: O(n) where n is the number of houses.
         * Space complexity: O(1) using only three variables.
         */
        
        // Track min cost to paint houses ending with each color.
        int red = 0, blue = 0, green = 0;
        
        for (const auto& cost : costs) {
            // Store current values before updating.
            int prev_red = red, prev_blue = blue, prev_green = green;
            
            // Calculate new min costs for current house.
            // To paint red, previous must be blue or green.
            red = min(prev_blue, prev_green) + cost[0];
            // To paint blue, previous must be red or green.
            blue = min(prev_red, prev_green) + cost[1];
            // To paint green, previous must be red or blue.
            green = min(prev_red, prev_blue) + cost[2];
        }
        
        // Return minimum of all three options.
        return min({red, blue, green});
    }
};
