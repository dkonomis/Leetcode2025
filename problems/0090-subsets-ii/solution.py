class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        """
        Problem: 0090 - Subsets II

        Given a list of integers that may contain duplicates, return all possible subsets
        (the power set), ensuring no duplicate subsets in the output.

        Approach:
        - First, sort the input to group duplicates together.
        - Use backtracking to generate all subsets.
        - At each level, skip elements that are the same as the previous
          (i.e., nums[i] == nums[i - 1]) if we're at the same recursion depth.
        - This ensures we don't generate duplicate subsets.

        Time complexity: O(2^n)
        Space complexity: O(n) for recursion stack
        """
        nums.sort()  # Sort to group duplicates together.
        res = []

        def backtrack(start: int, path: List[int]):
            res.append(path[:])  # Add current subset to result.

            # Explore further elements starting from 'start' index.
            for i in range(start, len(nums)):
                # Skip duplicates: if the current element is the same as the previous one,
                # and we are at the same level of recursion, skip it.
                if i > start and nums[i] == nums[i - 1]:
                    continue

                path.append(nums[i])       # Choose nums[i].
                backtrack(i + 1, path)     # Recurse with next index.
                path.pop()                 # Backtrack.

        backtrack(0, [])
        return res

