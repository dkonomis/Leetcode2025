class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        Problem: 0134 - Gas Station
        
        Find starting gas station index to complete circuit, or -1 if impossible.
        
        Approach:
        1. Check if total gas >= total cost (necessary condition).
        2. Use greedy approach: if we fail at station j starting from i,
           skip all stations between i and j as potential starting points.
        3. Track current tank and reset start when tank goes negative.
        
        Time complexity: O(n) where n is number of stations.
        Space complexity: O(1) using only constant extra space.
        */
        
        int total_gas = 0, total_cost = 0;
        
        // Calculate total gas and cost.
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
        }
        
        // If total gas < total cost, impossible to complete circuit.
        if (total_gas < total_cost) {
            return -1;
        }
        
        int current_tank = 0;
        int start = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            // Add gas and subtract cost for current station.
            current_tank += gas[i] - cost[i];
            
            // If tank goes negative, we can't reach next station.
            if (current_tank < 0) {
                // Reset: try starting from next station.
                start = i + 1;
                current_tank = 0;
            }
        }
        
        return start;
    }
};
