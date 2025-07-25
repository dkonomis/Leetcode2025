# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        """
        Problem: 0278 - First Bad Version
        
        Find the first bad version using binary search. Since versions are
        sequential and all versions after a bad one are also bad, we can
        use binary search to minimize API calls.
        
        Time complexity: O(log n).
        Space complexity: O(1).
        """
        # Binary search bounds.
        left = 1
        right = n
        
        # Search for the first bad version.
        while left < right:
            # Calculate middle to avoid overflow.
            mid = left + (right - left) // 2
            
            if isBadVersion(mid):
                # Mid is bad, first bad version is mid or earlier.
                right = mid
            else:
                # Mid is good, first bad version is after mid.
                left = mid + 1
        
        # Left points to the first bad version.
        res = left
        return res
