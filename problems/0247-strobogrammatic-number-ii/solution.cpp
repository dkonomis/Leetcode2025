class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        /*
         * Problem: 0247 - Strobogrammatic Number II
         * 
         * Generate all strobogrammatic numbers of length n.
         * Build iteratively from center outward, adding valid pairs.
         * Start with base cases and expand by 2 digits each iteration.
         * 
         * Time complexity: O(5^(n/2)) for the number of valid combinations.
         * Space complexity: O(5^(n/2)) for storing results.
         */
        
        vector<pair<char, char>> reversible_pairs = {
            {'0', '0'}, {'1', '1'}, 
            {'6', '9'}, {'8', '8'}, {'9', '6'}
        };
        
        // When n is even (n % 2 == 0), we start with strings of length 0.
        // When n is odd (n % 2 == 1), we start with strings of length 1.
        int curr_len = n % 2;
        
        // Initialize with base cases.
        vector<string> queue;
        if (curr_len == 1) {
            queue = {"0", "1", "8"};
        } else {
            queue = {""};
        }
        
        // Build up to length n by adding pairs.
        while (curr_len < n) {
            curr_len += 2;
            vector<string> next_level;
            
            // Add pairs around each existing number.
            for (const string& num : queue) {
                for (const auto& pair : reversible_pairs) {
                    // Avoid leading zeros when building final length.
                    if (curr_len != n || pair.first != '0') {
                        next_level.push_back(pair.first + num + pair.second);
                    }
                }
            }
            
            queue = next_level;
        }
        
        return queue;
    }
};
