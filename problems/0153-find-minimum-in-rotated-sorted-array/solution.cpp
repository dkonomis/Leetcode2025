class Solution {
public:
    int findMin(vector<int>& nums) {
        /**
         * Problem: 0153 - Find Minimum in Rotated Sorted Array
         * 
         * Find minimum element in a rotated sorted array.
         * 
         * Approach:
         * Binary search. The minimum is at the rotation point.
         * Compare mid with right to determine which half to search:
         * - If mid > right: minimum is in right half
         * - If mid < right: minimum is in left half (including mid)
         * 
         * Time complexity: O(log n).
         * Space complexity: O(1).
         */
        
        int left = 0;
        int right = nums.size() - 1;
        
        // Binary search for the rotation point.
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid element is greater than right element,
            // the minimum must be in the right half.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Otherwise, minimum is in left half (including mid).
                // Mid could be the minimum, so don't exclude it.
                right = mid;
            }
        }
        
        // Left and right converge to the minimum element.
        return nums[left];
    }
};
