class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        /*
        Problem: 0163 - Missing Ranges
        
        Given a sorted array and range [lower, upper], find all missing ranges.
        Return list of [start, end] pairs representing consecutive missing numbers.
        
        Approach:
        - Handle empty array case first
        - Check for missing range before first element
        - Check gaps between consecutive elements
        - Check for missing range after last element
        - Each gap of size > 1 represents a missing range
        
        Time complexity: O(n).
        Space complexity: O(1).
        */
        
        int n = nums.size();
        vector<vector<int>> res;
        
        // Handle empty array case.
        if (n == 0) {
            return {{lower, upper}};
        }
        
        // Check for missing range before first element.
        if (nums[0] > lower) {
            res.push_back({lower, nums[0] - 1});
        }
        
        // Check gaps between consecutive elements.
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > 1) {
                // Found a gap, add missing range.
                res.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }
        
        // Check for missing range after last element.
        if (nums[n - 1] < upper) {
            res.push_back({nums[n - 1] + 1, upper});
        }
        
        return res;
    }
};
