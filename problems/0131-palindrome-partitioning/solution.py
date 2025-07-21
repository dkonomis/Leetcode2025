class Solution:
    def partition(self, s: str) -> List[List[str]]:
        """
        Problem: 0131 - Palindrome Partitioning
        
        Find all possible palindrome partitioning of string s.
        
        Approach:
        1. Use backtracking to try all possible partitions.
        2. At each position, try all palindromic substrings starting from that position.
        3. Recursively partition the remaining string.
        4. Add complete partition when reaching end of string.
        
        Time complexity: O(2^n * n) where n is length of string.
        Space complexity: O(n) for recursion stack and current partition.
        """
        def is_palindrome(string: str) -> bool:
            # Check if string is palindrome using two pointers.
            left, right = 0, len(string) - 1
            
            # Move pointers toward center.
            while left < right:
                # If characters don't match, not a palindrome.
                if string[left] != string[right]:
                    return False
                # Move both pointers inward.
                left += 1
                right -= 1
            
            # All characters matched, it's a palindrome.
            return True
        
        res = []
        current_partition = []
        
        def backtrack(start: int) -> None:
            # Base case: reached end of string.
            if start == len(s):
                res.append(current_partition[:])  # Add copy of current partition.
                return
            
            # Try all possible substrings starting from current position.
            for end in range(start + 1, len(s) + 1):
                substring = s[start:end]
                
                # If substring is palindrome, include it in partition.
                if is_palindrome(substring):
                    # Choose: add substring to current partition.
                    current_partition.append(substring)
                    
                    # Explore: recursively partition remaining string.
                    backtrack(end)
                    
                    # Unchoose: remove substring for next iteration.
                    current_partition.pop()
        
        backtrack(0)
        return res
