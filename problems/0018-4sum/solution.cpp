#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        /*
        Problem 0018 – 4Sum.

        Given an integer array nums and an integer target, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
        such that: 0 <= a, b, c, d < n, and a, b, c, d are distinct, and nums[a] + nums[b] + nums[c] + nums[d] == target.

        Return the answer in any order.

        This implementation generalizes to kSum using recursion.

        Time Complexity  : O(n^{k−1}) = O(n^3) when k = 4.
        Space Complexity : O(k) recursion depth + O(1) auxiliary.
        */

        std::sort(nums.begin(), nums.end());  // Sort to allow two-pointer technique and skip duplicates.
        return kSum(nums, target, 0, 4);
    }

private:
    std::vector<std::vector<int>> kSum(const std::vector<int>& nums, long long target, int start, int k) {
        std::vector<std::vector<int>> res;
        int n = nums.size();

        // Base case: not enough numbers to consider.
        if (start == n) return res;

        // Early termination if smallest value too big or largest too small.
        long long average_value = target / k;
        if (nums[start] > average_value || nums[n - 1] < average_value) return res;

        if (k == 2) return twoSum(nums, target, start);

        for (int i = start; i < n; ++i) {
            // Skip duplicates.
            if (i == start || nums[i - 1] != nums[i]) {
                // Recursive call for k-1 sum.
                std::vector<std::vector<int>> subsets = kSum(nums, target - nums[i], i + 1, k - 1);
                for (const std::vector<int>& subset : subsets) {
                    std::vector<int> combination = {nums[i]};
                    combination.insert(combination.end(), subset.begin(), subset.end());
                    res.push_back(combination);
                }
            }
        }

        return res;
    }

    std::vector<std::vector<int>> twoSum(const std::vector<int>& nums, long long target, int start) {
        std::vector<std::vector<int>> res;
        int left = start, right = nums.size() - 1;

        while (left < right) {
            int lo = nums[left];
            int hi = nums[right];
            long long curr_sum = lo + hi;

            if (curr_sum < target || (left > start && nums[left] == nums[left - 1])) {
                ++left;
            } else if (curr_sum > target || (right < nums.size() - 1 && nums[right] == nums[right + 1])) {
                --right;
            } else {
                res.push_back({nums[left], nums[right]});
                ++left;
                --right;
            }
        }

        return res;
    }
};

