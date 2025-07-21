class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """
        Problem: 0134 - Gas Station
        
        Find starting gas station index to complete circuit, or -1 if impossible.
        
        Approach:
        1. Check if total gas >= total cost (necessary condition).
        2. Use greedy approach: if we fail at station j starting from i,
           skip all stations between i and j as potential starting points.
        3. Track current tank and reset start when tank goes negative.
        
        Time complexity: O(n) where n is number of stations.
        Space complexity: O(1) using only constant extra space.
        """
        total_gas = sum(gas)
        total_cost = sum(cost)
        
        # If total gas < total cost, impossible to complete circuit.
        if total_gas < total_cost:
            return -1
        
        current_tank = 0
        start = 0
        
        for i in range(len(gas)):
            # Add gas and subtract cost for current station.
            current_tank += gas[i] - cost[i]
            
            # If tank goes negative, we can't reach next station.
            if current_tank < 0:
                # Reset: try starting from next station.
                start = i + 1
                current_tank = 0
        
        return start
