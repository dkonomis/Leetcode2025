#include <vector>
#include <algorithm>
#include <cstdlib>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        /*
        Problem 0016 – 3Sum Closest.

        Given an integer array nums and an integer target, find three integers in nums
        such that the sum is closest to target. Return the sum of the three integers.

        It is guaranteed that exactly one solution exists.

        Time Complexity  : O(n^2), where n = nums.size().
        Space Complexity : O(1).
        */

        std::sort(nums.begin(), nums.end());  // Sort the array to use two-pointer technique.

        int closest = nums[0] + nums[1] + nums[2];  // Initialize with the first triplet.

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            size_t left = i + 1;
            size_t right = nums.size() - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                // Update the closest sum if needed.
                if (std::abs(total - target) < std::abs(closest - target)) {
                    closest = total;
                }

                if (total < target) {
                    ++left;  // Need a larger sum.
                } else if (total > target) {
                    --right;  // Need a smaller sum.
                } else {
                    return target;  // Exact match found.
                }
            }
        }

        return closest;  // Return the closest sum found.
    }
};

