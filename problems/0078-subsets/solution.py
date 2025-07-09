class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """
        Problem: 0078 - Subsets

        Given a list of unique integers, return all possible subsets (the power set).

        Approach:
        - Use backtracking to explore each element's inclusion or exclusion.
        - At each recursive call, record the current subset path.
        - Recurse forward to explore adding more elements.
        - Always include a copy of the current path in the result.

        Time complexity: O(n × 2^n), where n is the number of elements in nums.
        Space complexity: O(n) for the recursion call stack.
        """
        res = []

        def backtrack(start: int, path: List[int]):
            res.append(path[:])  # Add the current subset to the result.

            # Explore further elements to include in the subset.
            for i in range(start, len(nums)):
                path.append(nums[i])  # Choose nums[i].
                backtrack(i + 1, path)  # Recurse forward.
                path.pop()  # Backtrack by removing last element.

        backtrack(0, [])
        return res

