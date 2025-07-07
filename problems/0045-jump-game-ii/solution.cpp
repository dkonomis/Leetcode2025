class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        0045. Jump Game II

        Given an array nums where each element represents the maximum jump length from that position,
        return the minimum number of jumps required to reach the last index.

        Approach:
        We use a greedy strategy:
        - We track the current range (window) that can be reached with the current number of jumps.
        - We also track the farthest index we can reach during this window.
        - Whenever we reach the end of the current window, we increment the jump counter
          and update the window to the farthest index found so far.

        Time complexity: O(n), where n is the length of nums.
        We make a single pass through the array.

        Space complexity: O(1), we only use a few integer variables.
        */

        int n = nums.size();
        int jumps = 0;         // Number of jumps made so far.
        int farthest = 0;      // The farthest index reachable in current scan.
        int end = 0;           // End of the current jump's window.

        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest index we can reach from index i.
            farthest = max(farthest, i + nums[i]);

            // If we reached the end of the current jump's range.
            if (i == end) {
                ++jumps;          // Make a jump.
                end = farthest;   // Move window to the farthest reach.
            }
        }

        return jumps;
    }
};

