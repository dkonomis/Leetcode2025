#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        0033. Search in Rotated Sorted Array

        Problem:
        Given a rotated sorted array with unique integers, return the index of target if it exists, 
        or -1 otherwise. Must run in O(log n) time.

        Approach:
        Use modified binary search:
        - At each step, one half (left or right) must be sorted.
        - Determine which half is sorted and whether the target lies within it.
        - Adjust search bounds accordingly.

        Time complexity: O(log n)
        Space complexity: O(1)
        */

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;  // Found the target.
            }

            if (nums[left] <= nums[mid]) {
                // Left half is sorted.
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Target is in the left half.
                } else {
                    left = mid + 1;   // Target is in the right half.
                }
            } else {
                // Right half is sorted.
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // Target is in the right half.
                } else {
                    right = mid - 1;  // Target is in the left half.
                }
            }
        }

        return -1;  // Target not found.
    }
};

