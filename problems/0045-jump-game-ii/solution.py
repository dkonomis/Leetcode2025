from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        """
        0045. Jump Game II

        Given an array nums where each element represents the maximum jump length from that position,
        return the minimum number of jumps required to reach the last index.

        Approach:
        Use a greedy strategy:
        - Track the current window (range of indices reachable with the current number of jumps).
        - Track the farthest index reachable from the current window.
        - When we reach the end of the current window, increment jump count and move to the farthest.

        Time complexity: O(n), where n is the length of nums.
        Each element is visited once to update the farthest reachable index.

        Space complexity: O(1), only a few integer variables are used.
        """

        n = len(nums)
        jumps = 0              # Number of jumps made so far.
        farthest = 0           # The farthest index reachable in the current scan.
        end = 0                # End of the current jump's window.

        for i in range(n - 1):
            # Update the farthest index reachable from this position.
            farthest = max(farthest, i + nums[i])

            # If we reach the end of the current jump window:
            if i == end:
                jumps += 1       # Make a jump.
                end = farthest   # Update window to farthest reach.

        return jumps

