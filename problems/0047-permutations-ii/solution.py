from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        """
        0047. Permutations II

        Given a list of integers `nums` (which may contain duplicates), return all unique permutations.

        Approach:
        - Sort the input list to ensure that duplicates are adjacent.
        - Use backtracking to generate permutations.
        - Track used indices to avoid repeating elements.
        - Skip duplicates by ensuring that for nums[i] == nums[i - 1], we only use it
          if the previous identical element has been used in the current branch.

        Time complexity: O(N*N!),
        where N is the number of elements in nums. There are at most N! permutations.
        Pruning duplicate branches reduces this significantly in practice.

        Space complexity: O(N),
        for recursion and tracking used elements.
        """

        nums.sort()  # Sort to make duplicate detection easier.
        res = []
        used = [False] * len(nums)

        def backtrack(path: List[int]) -> None:
            if len(path) == len(nums):
                res.append(path[:])
                return

            # Try each unused number at the current level.
            for i in range(len(nums)):
                if used[i]:
                    continue

                # Skip duplicates: if current is same as previous and previous was not used.
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue

                # Choose nums[i].
                used[i] = True
                path.append(nums[i])

                # Recurse with nums[i] included.
                backtrack(path)

                # Backtrack.
                path.pop()
                used[i] = False

        backtrack([])
        return res

