class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        """
        Problem: 0254 - Factor Combinations
        
        Find all combinations of factors for n using backtracking.
        Start from factor 2 and recursively divide n by valid factors.
        To avoid duplicates, only consider factors >= previous factor.
        Key insight: factors are bounded by sqrt(n).
        
        Time complexity: O(sqrt(n)^d) where d is the recursion depth.
        Space complexity: O(log n) for the recursion depth.
        """
        def backtrack(num, start, path):
            # Add current factorization if path is not empty.
            if path:
                res.append(path + [num])
            
            # Try all possible factors from start to sqrt(num).
            i = start
            while i * i <= num:
                if num % i == 0:
                    # Include factor i and recurse with num/i.
                    path.append(i)
                    # Recursively find factors of the quotient.
                    backtrack(num // i, i, path)
                    # Backtrack.
                    path.pop()
                i += 1
        
        res = []
        # Start backtracking from factor 2 with empty path.
        backtrack(n, 2, [])
        return res
