class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        /**
         * Problem: 0254 - Factor Combinations
         * 
         * Find all combinations of factors for n using backtracking.
         * Start from factor 2 and recursively divide n by valid factors.
         * To avoid duplicates, only consider factors >= previous factor.
         * Key insight: factors are bounded by sqrt(n).
         * 
         * Time complexity: O(sqrt(n)^d) where d is the recursion depth.
         * Space complexity: O(log n) for the recursion depth.
         */
        
        vector<vector<int>> res;
        vector<int> path;
        
        // Lambda function for backtracking.
        function<void(int, int)> backtrack = [&](int num, int start) {
            // Add current factorization if path is not empty.
            if (!path.empty()) {
                vector<int> combination = path;
                combination.push_back(num);
                res.push_back(combination);
            }
            
            // Try all possible factors from start to sqrt(num).
            for (int i = start; i * i <= num; i++) {
                if (num % i == 0) {
                    // Include factor i and recurse with num/i.
                    path.push_back(i);
                    // Recursively find factors of the quotient.
                    backtrack(num / i, i);
                    // Backtrack.
                    path.pop_back();
                }
            }
        };
        
        // Start backtracking from factor 2 with empty path.
        backtrack(n, 2);
        return res;
    }
};
