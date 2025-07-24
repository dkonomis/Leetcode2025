class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        /**
         * Problem: 0259 - 3Sum Smaller
         * 
         * Sort array then use three pointers. For each fixed element i,
         * use two pointers (left, right) to find pairs where sum < target.
         * When nums[i] + nums[left] + nums[right] < target, all elements
         * between left and right form valid triplets, so add (right - left).
         * 
         * Time complexity: O(n²) where n is the length of nums.
         * Space complexity: O(1) excluding the sort space.
         */
        
        // Sort array for two-pointer approach.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        
        // Fix first element.
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            // Two-pointer search for valid pairs.
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                
                if (total < target) {
                    // All elements between left and right form valid triplets.
                    res += right - left;
                    left++;
                } else {
                    // Sum too large, decrease right pointer.
                    right--;
                }
            }
        }
        
        return res;
    }
};
