class Solution {
public:
    vector<string> addOperators(string num, int target) {
        /**
         * Problem: 0282 - Expression Add Operators
         * 
         * Generate all valid expressions by inserting +, -, * operators between
         * digits that evaluate to target. Uses backtracking with careful handling
         * of operator precedence and leading zeros.
         * 
         * Approach:
         * - Try all possible ways to split num into operands
         * - For each operand, try all three operators (+, -, *)
         * - Track previous operand to handle multiplication precedence correctly
         * - Skip numbers with leading zeros (except "0" itself)
         * 
         * Time complexity: O(n * 4^n) where n is length of num.
         * Space complexity: O(n) for recursion stack and path building.
         */
        vector<string> res;
        backtrack(num, target, 0, "", 0, 0, res);
        return res;
    }
    
private:
    void backtrack(const string& num, int target, int index, 
                   string path, long value, long prev, 
                   vector<string>& res) {
        // Base case: processed all digits.
        if (index == num.length()) {
            if (value == target) {
                res.push_back(path);
            }
            return;
        }
        
        // Try all possible numbers starting at current index.
        for (int i = index; i < num.length(); i++) {
            // Skip numbers with leading zeros (except "0" itself).
            if (i != index && num[index] == '0') {
                break;
            }
            
            // Extract current number.
            string curr_str = num.substr(index, i - index + 1);
            long curr_num = stol(curr_str);
            
            // First number in expression (no operator before it).
            if (index == 0) {
                backtrack(num, target, i + 1, curr_str, curr_num, curr_num, res);
            } else {
                // Try addition.
                backtrack(num, target, i + 1, 
                         path + '+' + curr_str, 
                         value + curr_num, 
                         curr_num, 
                         res);
                
                // Try subtraction.
                backtrack(num, target, i + 1, 
                         path + '-' + curr_str, 
                         value - curr_num, 
                         -curr_num, 
                         res);
                
                // Try multiplication.
                // Need to undo last operation and apply multiplication.
                backtrack(num, target, i + 1, 
                         path + '*' + curr_str, 
                         value - prev + prev * curr_num, 
                         prev * curr_num, 
                         res);
            }
        }
    }
};
