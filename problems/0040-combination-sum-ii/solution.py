from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        0040. Combination Sum II

        Given a collection of integers candidates (which may contain duplicates),
        return all unique combinations where the numbers sum to the given target.
        Each number may be used at most once in each combination.

        Approach:
        - Sort the candidates so we can easily skip duplicates at the same level.
        - Use backtracking to explore each index from `start` onward.
        - Each recursive call represents a new level in the decision tree.
        - At the same level, we skip over duplicate values to avoid generating duplicate combinations.

        Time complexity: O(2^N),
        where N is the number of candidates. In the worst case, the power set is explored.
        Pruning and duplicate skipping improve this in practice.

        Space complexity: O(N).
        This accounts for recursion depth.
        """

        res = []
        candidates.sort()  # Sort to easily detect duplicates.

        def backtrack(start: int, path: List[int], total: int) -> None:
            if total == target:
                res.append(path[:])
                return
            if total > target:
                return

            for i in range(start, len(candidates)):
                # Skip duplicate values at the same level of recursion.
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                # Add candidates[i] to the current path.
                path.append(candidates[i])

                # Recurse to the next level — use i+1 to avoid reusing the same element.
                backtrack(i + 1, path, total + candidates[i])

                # Backtrack — remove the last added number.
                path.pop()

        backtrack(0, [], 0)
        return res

