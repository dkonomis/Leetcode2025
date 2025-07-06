#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
        0035. Search Insert Position

        Problem:
        Given a sorted array of distinct integers and a target, return the index if found.
        If not, return the index where it would be inserted to maintain the sorted order.
        Must run in O(log n) time.

        Approach:
        Use binary search to find the first index where nums[i] >= target.

        Time complexity: O(log n)
        Space complexity: O(1)
        */

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;  // Exact match found.
            } else if (nums[mid] < target) {
                left = mid + 1;  // Target is in the right half.
            } else {
                right = mid - 1;  // Target is in the left half.
            }
        }

        return left;  // Left is the insert position.
    }
};

