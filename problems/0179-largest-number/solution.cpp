class Solution {
public:
    string largestNumber(vector<int>& nums) {
        /**
         * Problem: 0179 - Largest Number
         * 
         * Given a list of non-negative integers, arrange them to form the largest number.
         * We need to sort the numbers based on which arrangement produces a larger result
         * when concatenated.
         * 
         * Approach:
         * - Convert all numbers to strings for comparison
         * - Define a custom comparator that compares str(a) + str(b) vs str(b) + str(a)
         * - Sort using this comparator to get the optimal ordering
         * - Handle edge case where all numbers are 0
         * 
         * Time complexity: O(n log n * k) where k is the average string length.
         * Space complexity: O(n) for the string conversions.
         */
        
        // Convert all integers to strings for comparison.
        vector<string> num_strings;
        for (int num : nums) {
            num_strings.push_back(to_string(num));
        }
        
        // Sort based on the custom comparator.
        sort(num_strings.begin(), num_strings.end(), [](const string& a, const string& b) {
            // Compare which concatenation order gives a larger number.
            return a + b > b + a;
        });
        
        // Handle edge case where all numbers are zeros.
        if (num_strings[0] == "0") {
            return "0";
        }
        
        // Concatenate all strings to form the largest number.
        string res = "";
        for (const string& s : num_strings) {
            res += s;
        }
        
        return res;
    }
};
