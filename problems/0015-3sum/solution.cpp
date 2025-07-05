#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        /*
        Problem 0015 – 3Sum.

        Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]]
        such that i ≠ j, i ≠ k, and j ≠ k, and nums[i] + nums[j] + nums[k] == 0.

        The solution set must not contain duplicate triplets.

        Time Complexity  : O(n^2), where n = nums.size().
        Space Complexity : O(k) for the output list, O(1) auxiliary.
        */

        std::vector<std::vector<int>> res;

        std::sort(nums.begin(), nums.end());  // Sort the array to apply two-pointer technique.

        for (size_t i = 0; i < nums.size(); ++i) {
            // Skip duplicate values for the first element of the triplet.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            size_t left = i + 1;              // Initialize the second pointer.
            size_t right = nums.size() - 1;   // Initialize the third pointer.

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total < 0) {
                    ++left;  // Need a larger value.
                } else if (total > 0) {
                    --right;  // Need a smaller value.
                } else {
                    // Found a valid triplet.
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element.
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }

                    // Skip duplicates for the third element.
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }

                    ++left;
                    --right;
                }
            }
        }

        return res;
    }
};

