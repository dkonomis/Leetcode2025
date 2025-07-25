# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        """
        Problem: 0277 - Find the Celebrity
        
        Find the celebrity using two-pass elimination. First pass narrows
        down to one candidate. Second pass verifies if this candidate is
        truly a celebrity. Key insight: if A knows B, then A cannot be
        celebrity; if A doesn't know B, then B cannot be celebrity.
        
        Time complexity: O(n).
        Space complexity: O(1).
        """
        # First pass: find the candidate.
        candidate = 0
        for i in range(1, n):
            if knows(candidate, i):
                # If candidate knows i, candidate can't be celebrity.
                candidate = i
        
        # Second pass: verify the candidate.
        for i in range(n):
            if i == candidate:
                continue
            
            # Celebrity should not know anyone and everyone should know celebrity.
            if knows(candidate, i) or not knows(i, candidate):
                return -1
        
        res = candidate
        return res
