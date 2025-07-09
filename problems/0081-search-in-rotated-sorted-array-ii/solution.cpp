class Solution {
public:
    /*
    Problem: 0081 - Search in Rotated Sorted Array II

    Given a rotated sorted array that may contain duplicates, determine if a target exists.

    Approach:
    - Use a modified binary search.
    - If nums[left] == nums[mid], we cannot determine which half is sorted, so increment left and decrement right.
    - Otherwise, determine if left-to-mid or mid-to-right is sorted and apply standard binary search logic.

    Time Complexity: O(log n) on average, but O(n) in the worst case due to duplicates.
    Space Complexity: O(1).
    */
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // If we can't determine the sorted half due to duplicates, shrink the range.
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            }
            else if (nums[left] <= nums[mid]) {
                // Left to mid is sorted.
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                // Mid to right is sorted.
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

