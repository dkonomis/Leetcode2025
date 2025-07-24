class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        """
        Problem: 0256 - Paint House
        
        Dynamic programming approach tracking minimum cost to paint houses
        ending with each color. For each house, calculate the minimum cost
        to paint it each color based on previous house's different colors.
        
        Time complexity: O(n) where n is the number of houses.
        Space complexity: O(1) using only three variables.
        """
        # Track min cost to paint houses ending with each color.
        red = blue = green = 0
        
        for cost in costs:
            # Calculate new min costs for current house.
            # To paint red, previous must be blue or green.
            new_red = min(blue, green) + cost[0]
            # To paint blue, previous must be red or green.
            new_blue = min(red, green) + cost[1]
            # To paint green, previous must be red or blue.
            new_green = min(red, blue) + cost[2]
            
            # Update costs for next iteration.
            red, blue, green = new_red, new_blue, new_green
        
        # Return minimum of all three options.
        return min(red, blue, green)
