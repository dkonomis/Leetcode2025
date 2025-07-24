class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        """
        Problem: 0265 - Paint House II
        
        Find minimum cost to paint n houses with k colors where no two adjacent houses
        can have the same color.
        
        Approach: Dynamic programming. For each house, calculate the minimum cost of painting
        it with each color by adding the minimum cost from the previous house (excluding the
        same color). Build up the solution house by house.
        
        Time complexity: O(n * k^2) where n is number of houses and k is number of colors.
        Space complexity: O(1) as we modify the input array in-place.
        """
        n = len(costs)
        if n == 0:
            return 0
        k = len(costs[0])
        
        # For each house starting from the second one.
        for house in range(1, n):
            # For each color option for current house.
            for color in range(k):
                best = math.inf
                # Find the minimum cost from previous house excluding same color.
                for prev_color in range(k):
                    if color == prev_color:
                        continue
                    best = min(best, costs[house-1][prev_color])
                # Add the best previous cost to current house cost.
                costs[house][color] += best
        
        # Return the minimum cost from the last house.
        return min(costs[n-1])
