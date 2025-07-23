class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        """
        Problem: 0216 - Combination Sum III
        
        Find all combinations of k numbers from 1-9 that sum to n.
        Use backtracking to explore all valid combinations.
        Prune branches early when sum exceeds n or we have too many numbers.
        
        Time complexity: O(C(9,k)) where C is the binomial coefficient.
        Space complexity: O(k) for the recursion stack and current combination.
        """
        res = []
        current = []
        
        def backtrack(start: int, remaining_sum: int, remaining_count: int):
            # Base case: found valid combination.
            if remaining_count == 0 and remaining_sum == 0:
                res.append(current[:])
                return
            
            # Pruning: invalid state.
            if remaining_count == 0 or remaining_sum <= 0:
                return
            
            # Try each number from start to 9.
            for num in range(start, 10):
                # Pruning: num is too large for remaining sum.
                if num > remaining_sum:
                    break
                
                # Choose current number.
                current.append(num)
                
                # Explore with this choice.
                backtrack(num + 1, remaining_sum - num, remaining_count - 1)
                
                # Backtrack: remove current number.
                current.pop()
        
        # Start backtracking from 1.
        backtrack(1, n, k)
        
        return res
