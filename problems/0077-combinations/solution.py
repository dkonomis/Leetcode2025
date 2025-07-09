class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        """
        Problem: 0077 - Combinations

        Given two integers n and k, return all possible combinations of k numbers chosen from 1 to n.

        Approach:
        - Use backtracking to generate all valid combinations.
        - At each step, decide whether to include the next number in the current path.
        - Stop recursion when the current path contains exactly k numbers.

        Time complexity: O(C(n, k)), where C(n, k) is the number of combinations.
        Space complexity: O(k) for the current path stack.
        """
        res = []

        def backtrack(start: int, path: List[int]):
            # If we have a complete combination, add it to the result.
            if len(path) == k:
                res.append(path[:])
                return

            # Explore remaining numbers starting from 'start'.
            for i in range(start, n - (k-len(path)-1) + 1):
                path.append(i)  # Choose number i.
                backtrack(i + 1, path)  # Recurse with next start.
                path.pop()  # Backtrack to explore other options.

        backtrack(1, [])
        return res

