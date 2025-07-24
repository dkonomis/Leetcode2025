class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        /*
         * Problem: 0248 - Strobogrammatic Number III
         * 
         * Count strobogrammatic numbers in range [low, high].
         * Generate all strobogrammatic numbers for each length in range.
         * Check if each generated number falls within the bounds.
         * 
         * Time complexity: O(5^(n/2) * n) where n is the max length.
         * Space complexity: O(5^(n/2)) for storing generated numbers.
         */
        
        int count = 0;
        
        // Process each possible length.
        for (int length = low.length(); length <= high.length(); length++) {
            // Generate all strobogrammatic numbers of current length.
            vector<string> nums = findStrobogrammatic(length);
            
            for (const string& num : nums) {
                // Skip numbers with leading zeros (except "0" itself).
                if (num.length() > 1 && num[0] == '0') {
                    continue;
                }
                
                // Check if number is in range [low, high].
                if (length == low.length() && num < low) {
                    continue;
                }
                if (length == high.length() && num > high) {
                    continue;
                }
                
                count++;
            }
        }
        
        return count;
    }
    
private:
    vector<string> findStrobogrammatic(int n) {
        // Generate all strobogrammatic numbers of length n.
        vector<pair<char, char>> reversible_pairs = {
            {'0', '0'}, {'1', '1'}, 
            {'6', '9'}, {'8', '8'}, {'9', '6'}
        };
        
        // Start with base cases.
        int curr_len = n % 2;
        vector<string> queue;
        if (curr_len == 1) {
            queue = {"0", "1", "8"};
        } else {
            queue = {""};
        }
        
        // Build up to length n.
        while (curr_len < n) {
            curr_len += 2;
            vector<string> next_level;
            
            for (const string& num : queue) {
                for (const auto& pair : reversible_pairs) {
                    next_level.push_back(pair.first + num + pair.second);
                }
            }
            
            queue = next_level;
        }
        
        return queue;
    }
};
