#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        53. Maximum Subarray

        Summary:
        Find the contiguous subarray with the largest sum using Kadane's Algorithm.

        Approach:
        - Track the maximum subarray sum ending at the current index (curr_sum).
        - Track the global maximum subarray sum found so far (max_sum).
        - At each step:
            - Either extend the previous subarray or start a new one at current element.
            - Update max_sum if curr_sum exceeds it.

        Time complexity: O(n), where n = nums.size()
        Space complexity: O(1)
        */
        int curr_sum = nums[0];  // max subarray sum ending at index 0.
        int max_sum = nums[0];   // global maximum subarray sum.

        for (int i = 1; i < nums.size(); ++i) {
            curr_sum = max(nums[i], curr_sum + nums[i]);  // extend or restart.
            max_sum = max(max_sum, curr_sum);             // update global max.
        }

        return max_sum;
    }
};

