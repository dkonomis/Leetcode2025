class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        /**
         * Problem: 0216 - Combination Sum III
         * 
         * Find all combinations of k numbers from 1-9 that sum to n.
         * Use backtracking to explore all valid combinations.
         * Prune branches early when sum exceeds n or we have too many numbers.
         * 
         * Time complexity: O(C(9,k)) where C is the binomial coefficient.
         * Space complexity: O(k) for the recursion stack and current combination.
         */
        
        vector<vector<int>> res;
        vector<int> current;
        
        // Start backtracking from 1.
        backtrack(1, n, k, current, res);
        
        return res;
    }
    
private:
    void backtrack(int start, int remaining_sum, int remaining_count, 
                   vector<int>& current, vector<vector<int>>& res) {
        // Base case: found valid combination.
        if (remaining_count == 0 && remaining_sum == 0) {
            res.push_back(current);
            return;
        }
        
        // Pruning: invalid state.
        if (remaining_count == 0 || remaining_sum <= 0) {
            return;
        }
        
        // Try each number from start to 9.
        for (int num = start; num <= 9; num++) {
            // Pruning: num is too large for remaining sum.
            if (num > remaining_sum) {
                break;
            }
            
            // Choose current number.
            current.push_back(num);
            
            // Explore with this choice.
            backtrack(num + 1, remaining_sum - num, remaining_count - 1, current, res);
            
            // Backtrack: remove current number.
            current.pop_back();
        }
    }
};
