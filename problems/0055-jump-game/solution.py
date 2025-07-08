class Solution:
    def canJump(self, nums: list[int]) -> bool:
        """
        55. Jump Game

        Summary:
        Determine if you can reach the last index from the first index, given that
        each element in the array represents the maximum jump length from that position.

        Approach:
        - Use a greedy strategy to track the farthest index reachable so far.
        - Iterate through the array:
            - If current index is beyond the farthest reachable point, return False.
            - Otherwise, update the farthest reachable index.
        - If we make it through the loop, return True.

        Time complexity: O(n), where n = len(nums)
        Space complexity: O(1)
        """
        farthest = 0  # farthest index we can currently reach.

        for i in range(len(nums)):
            if i > farthest:
                return False  # cannot even reach current index.

            farthest = max(farthest, i + nums[i])  # update reach.

        return True  # successfully reached the end or beyond.

