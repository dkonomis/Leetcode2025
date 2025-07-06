#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        0034. Find First and Last Position of Element in Sorted Array

        Problem:
        Given a sorted array, find the starting and ending position of a given target value.
        If target is not found, return [-1, -1]. Must run in O(log n) time.

        Approach:
        Use a single binary search function with a 'find_first' flag.
        If find_first is true, we search for the leftmost index.
        If false, we search for the rightmost index.

        Time complexity: O(log n)
        Space complexity: O(1)
        */

        // Helper function to find either first or last occurrence.
        auto binary_search = [&](bool find_first) -> int {
            int left = 0;
            int right = nums.size() - 1;
            int pos = -1;  // Default result if not found.

            while (left <= right) {
                int mid = (left + right) / 2;

                if (nums[mid] == target) {
                    pos = mid;  // Save current position.
                    if (find_first) {
                        right = mid - 1;  // Narrow to left half.
                    } else {
                        left = mid + 1;   // Narrow to right half.
                    }
                } else if (nums[mid] < target) {
                    left = mid + 1;       // Search in right half.
                } else {
                    right = mid - 1;      // Search in left half.
                }
            }

            return pos;
        };

        return {binary_search(true), binary_search(false)};
    }
};

