class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /**
         * Problem: 0217 - Contains Duplicate
         * 
         * Check if array contains any duplicates using a hash set.
         * Add each element to set and return true if we find a duplicate.
         * 
         * Time complexity: O(n) where n is the length of the array.
         * Space complexity: O(n) for the hash set.
         */
        
        unordered_set<int> seen;
        
        // Check each number in the array.
        for (int num : nums) {
            // If number already in set, we found a duplicate.
            if (seen.count(num)) {
                return true;
            }
            // Add number to set.
            seen.insert(num);
        }
        
        // No duplicates found.
        return false;
    }
};
