class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        """
        Problem: 0060 - Permutation Sequence

        Given two integers n and k, return the k-th permutation of the numbers [1, 2, ..., n]
        in lexicographic order.

        Approach:
        - Precompute factorials from 0! to n!.
        - Use a list of digits [1..n] that can be selected in order.
        - Convert k to 0-based indexing for easier math.
        - For each position i from n-1 down to 0:
            - Compute the block index as k // fact[i].
            - Select and remove the corresponding digit.
            - Update k = k % fact[i] for the remaining part.

        Time complexity: O(n^2), due to list.pop(index).
        Space complexity: O(n), for factorial array and digit list.
        """
        # Precompute factorials up to n!
        fact = [1] * (n + 1)
        for i in range(2, n + 1):
            fact[i] = fact[i - 1] * i

        digits = list(range(1, n + 1))  # Available digits: [1, 2, ..., n]
        k -= 1  # Convert k to 0-based index

        res = []

        # Build the k-th permutation one digit at a time
        for i in range(n - 1, -1, -1):
            idx = k // fact[i]          # Choose idx-th digit from available
            k %= fact[i]                # Update k for the next position
            res.append(str(digits.pop(idx)))  # Append and remove the digit

        return "".join(res)

