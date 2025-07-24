class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        /*
         * Problem: 0241 - Different Ways to Add Parentheses
         * 
         * Compute all possible results by adding parentheses in different ways.
         * Use divide and conquer: split at each operator and recursively solve.
         * For each operator, compute all results from left and right subexpressions.
         * Combine them using the operator.
         * 
         * Time complexity: O(n * 2^n) where n is the number of operators.
         * Space complexity: O(2^n) for storing all possible results.
         */
        
        // Memoization to avoid recomputing same subexpressions.
        unordered_map<string, vector<int>> memo;
        return compute(expression, memo);
    }
    
private:
    vector<int> compute(const string& expr, unordered_map<string, vector<int>>& memo) {
        // Check if already computed.
        if (memo.count(expr)) {
            return memo[expr];
        }
        
        vector<int> res;
        
        // Try splitting at each operator.
        for (int i = 0; i < expr.length(); i++) {
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
                // Split expression at operator.
                string left_expr = expr.substr(0, i);
                string right_expr = expr.substr(i + 1);
                
                // Recursively compute all results for left and right.
                vector<int> left_results = compute(left_expr, memo);
                vector<int> right_results = compute(right_expr, memo);
                
                // Combine all left and right results using current operator.
                for (int left : left_results) {
                    for (int right : right_results) {
                        if (expr[i] == '+') {
                            res.push_back(left + right);
                        } else if (expr[i] == '-') {
                            res.push_back(left - right);
                        } else if (expr[i] == '*') {
                            res.push_back(left * right);
                        }
                    }
                }
            }
        }
        
        // Base case: no operators found, expr is just a number.
        if (res.empty()) {
            res.push_back(stoi(expr));
        }
        
        // Save to memo and return.
        memo[expr] = res;
        return res;
    }
};
