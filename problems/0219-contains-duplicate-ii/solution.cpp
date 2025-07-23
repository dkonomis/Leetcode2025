class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /**
         * Problem: 0219 - Contains Duplicate II
         * 
         * Check if array contains duplicates within k distance.
         * Use a sliding window with a hash set to track elements within k indices.
         * Remove elements that are more than k indices away.
         * 
         * Time complexity: O(n) where n is the length of the array.
         * Space complexity: O(min(n, k)) for the hash set.
         */
        
        unordered_set<int> window;
        
        // Process each element in the array.
        for (int i = 0; i < nums.size(); i++) {
            // If current number is already in window, found duplicate within k.
            if (window.count(nums[i])) {
                return true;
            }
            
            // Add current number to window.
            window.insert(nums[i]);
            
            // Remove element that is more than k indices away.
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        // No duplicates found within k distance.
        return false;
    }
};
