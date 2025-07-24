class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        /**
         * Problem: 0265 - Paint House II
         * 
         * Find minimum cost to paint n houses with k colors where no two adjacent houses
         * can have the same color.
         * 
         * Approach: Dynamic programming. For each house, calculate the minimum cost of painting
         * it with each color by adding the minimum cost from the previous house (excluding the
         * same color). Build up the solution house by house.
         * 
         * Time complexity: O(n * k^2) where n is number of houses and k is number of colors.
         * Space complexity: O(1) as we modify the input array in-place.
         */
        
        int n = costs.size();
        if (n == 0) {
            return 0;
        }
        int k = costs[0].size();
        
        // For each house starting from the second one.
        for (int house = 1; house < n; house++) {
            // For each color option for current house.
            for (int color = 0; color < k; color++) {
                int best = INT_MAX;
                // Find the minimum cost from previous house excluding same color.
                for (int prev_color = 0; prev_color < k; prev_color++) {
                    if (color == prev_color) {
                        continue;
                    }
                    best = min(best, costs[house-1][prev_color]);
                }
                // Add the best previous cost to current house cost.
                costs[house][color] += best;
            }
        }
        
        // Return the minimum cost from the last house.
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};
