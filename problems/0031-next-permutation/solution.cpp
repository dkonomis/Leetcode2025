#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        0031. Next Permutation

        Problem:
        Rearrange the list nums into its next lexicographical permutation. 
        If no such permutation exists, rearrange into the lowest possible order.

        Approach:
        1. Traverse from right to left to find the first decreasing element (pivot).
        2. If no pivot is found, reverse the entire list.
        3. Otherwise, find the smallest element greater than pivot from the right.
        4. Swap them, then reverse the suffix.

        Time complexity: O(n)
        Space complexity: O(1)
        */

        int n = nums.size();

        // Step 1: Find the pivot index.
        int pivot = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            // The array is in descending order. Reverse to get smallest permutation.
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than nums[pivot] to the right.
        for (int j = n - 1; j > pivot; --j) {
            if (nums[j] > nums[pivot]) {
                // Step 3: Swap pivot and that element.
                swap(nums[pivot], nums[j]);
                break;
            }
        }

        // Step 4: Reverse the suffix starting at pivot + 1.
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

