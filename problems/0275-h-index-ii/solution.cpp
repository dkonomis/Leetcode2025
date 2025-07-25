class Solution {
public:
    int hIndex(vector<int>& citations) {
        /**
         * Problem: 0275 - H-Index II
         * 
         * Find h-index from sorted array of citations (ascending order).
         * 
         * Approach: Binary search. For index i, there are n-i papers with at least
         * citations[i] citations. We want the largest h where h papers have >= h citations.
         * This translates to finding the largest i where citations[i] >= n-i.
         * 
         * Time complexity: O(log n) where n is number of papers.
         * Space complexity: O(1) using only pointers.
         */
        
        int n = citations.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Papers from mid to end: n - mid papers.
            // Each has at least citations[mid] citations.
            int h = n - mid;
            
            if (citations[mid] >= h) {
                // Can possibly increase h by looking left.
                right = mid - 1;
            } else {
                // Need more citations, look right.
                left = mid + 1;
            }
        }
        
        // After binary search, left points to first position where
        // citations[i] >= n-i, so h-index is n-left.
        return n - left;
    }
};
