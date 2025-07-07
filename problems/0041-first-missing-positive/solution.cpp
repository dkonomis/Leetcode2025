// 0041. First Missing Positive

#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        0041. First Missing Positive

        Problem:
        Given an unsorted integer array nums, return the smallest missing positive integer.
        Must run in O(n) time using constant extra space.

        Approach:
        - Use index marking (cyclic sort idea).
        - For each number x in [1, n], place it at index x - 1 if possible.
        - Iterate again to find the first index i where nums[i] != i + 1.
        - That i + 1 is the smallest missing positive.

        Time complexity: O(n), where n = nums.size().
        Each number is swapped at most once.

        Space complexity: O(1). All operations are done in-place.
        */

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Keep placing nums[i] in the correct index if it's in [1, n].
            while (
                nums[i] >= 1 && nums[i] <= n &&
                nums[nums[i] - 1] != nums[i]
            ) {
                // Swap nums[i] with nums[nums[i] - 1].
                int target_idx = nums[i] - 1;
                swap(nums[i], nums[target_idx]);
            }
        }

        // After rearranging, the first index i such that nums[i] != i + 1 is the answer.
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all values from 1 to n are present, the missing one is n + 1.
        return n + 1;
    }
};

