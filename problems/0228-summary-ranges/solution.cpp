class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        /**
         * Problem: 0228 - Summary Ranges
         * 
         * Find consecutive ranges in a sorted array.
         * Track start of each range and extend while numbers are consecutive.
         * Format as "a->b" for ranges or "a" for single numbers.
         * 
         * Time complexity: O(n) where n is the length of nums.
         * Space complexity: O(1) excluding the output list.
         */
        
        vector<string> res;
        
        if (nums.empty()) {
            return res;
        }
        
        int start = 0;  // Start index of current range.
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if current number breaks the consecutive sequence.
            // This happens at the last element or when next number is not consecutive.
            if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) {
                // Found end of current range.
                if (start == i) {
                    // Single number range.
                    res.push_back(to_string(nums[start]));
                } else {
                    // Multi-number range.
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
                }
                // Update start for next range.
                start = i + 1;
            }
        }
        
        return res;
    }
};
