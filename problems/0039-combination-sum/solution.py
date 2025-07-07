from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        0039. Combination Sum

        Given a list of distinct integers candidates and a target integer target,
        return all unique combinations of candidates where the chosen numbers sum to target.
        Each number in candidates may be used an unlimited number of times.

        Approach:
        Use backtracking to explore combinations. At each recursive call, we try all candidates
        starting from the current index (to allow reuse). We track the remaining sum,
        and backtrack when it becomes negative or zero.

        Time complexity: O(N^(T/M) + 1), 
        where N is the number of candidates, T is the target value, and M is the smallest candidate.
        The execution tree is a N-ary tree of height T/M, giving at most O(N^(T/M) + 1) nodes.

        Space complexity: O(T/M),
        which accounts for the recursion depth and the space to store the current path.
        We do not include the space required to store the final result.

        """

        res = []

        def backtrack(start: int, path: List[int], total: int) -> None:
            # Base case: exact match
            if total == target:
                res.append(path[:])
                return

            # Stop exploring if the total exceeds the target
            if total > target:
                return

            for i in range(start, len(candidates)):
                # Add number in the path.
                path.append(candidates[i])

                # candidates[i] can be included multiple times.
                backtrack(i, path, total + candidates[i])

                # Remove candidates[i] from path.
                path.pop()

        backtrack(0, [], 0)
        return res

