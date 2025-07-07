from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        """
        0046. Permutations

        Given a list of distinct integers nums, return all possible permutations.

        Approach:
        - Use backtracking to build permutations incrementally.
        - Keep a 'path' list for the current permutation.
        - Use a 'used' boolean list to track which elements are already in 'path'.
        - When path is complete (length equals len(nums)), add a copy to the result.

        Time complexity: O(N*N!)
        - There are N! permutations of N distinct numbers.
        - Each permutation takes O(N) time to build and copy.

        Space complexity: O(N)
        - We use recursion depth and a path of size N.
        - The result list is not counted in auxiliary space.
        """
        res = []
        used = [False] * len(nums)

        def backtrack(path: List[int]) -> None:
            # Base case: all numbers used, store a copy of the current permutation.
            if len(path) == len(nums):
                res.append(path[:])
                return
	    
	    # Try each unused number at the current position in the permutation.
            for i in range(len(nums)):
                if used[i]:
                    continue

                # Choose nums[i].
                used[i] = True
                path.append(nums[i])

                # Recurse with nums[i] included.
                backtrack(path)

                # Backtrack: remove nums[i] and mark as unused.
                path.pop()
                used[i] = False

        backtrack([])
        return res

