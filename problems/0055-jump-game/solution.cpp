#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
        55. Jump Game

        Summary:
        Determine if you can reach the last index, given that each element in nums
        represents your maximum jump length at that position.

        Approach:
        - Use a greedy strategy to track the farthest index reachable so far.
        - Iterate through the array:
            - If the current index is beyond the farthest reachable point, return false.
            - Otherwise, update the farthest reachable index.
        - If we complete the loop, the end is reachable.

        Time complexity: O(n), where n = nums.size()
        Space complexity: O(1)
        */
        int farthest = 0;  // farthest index reachable so far.

        for (int i = 0; i < nums.size(); ++i) {
            if (i > farthest) {
                return false;  // cannot reach this position.
            }

            farthest = max(farthest, i + nums[i]);  // update reach.
        }

        return true;  // successfully reached or passed the last index.
    }
};

