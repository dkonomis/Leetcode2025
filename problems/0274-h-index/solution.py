class Solution:
    def hIndex(self, citations: List[int]) -> int:
        """
        Problem: 0274 - H-Index
        
        Find the h-index: maximum h where at least h papers have h or more citations.
        
        Approach: Counting sort technique. Create buckets for citation counts.
        Papers with citations >= n are capped at n. Then traverse from high to low,
        accumulating papers until we find the h-index.
        
        Time complexity: O(n) where n is number of papers.
        Space complexity: O(n) for the count array.
        """
        n = len(citations)
        
        # Count papers by citation count (capped at n).
        count = [0] * (n + 1)
        for c in citations:
            # Papers with n or more citations go in bucket n.
            count[min(c, n)] += 1
        
        # Find h-index by traversing from high to low.
        papers = 0
        for h in range(n, -1, -1):
            papers += count[h]
            # Found h papers with at least h citations.
            if papers >= h:
                return h
        
        return 0
