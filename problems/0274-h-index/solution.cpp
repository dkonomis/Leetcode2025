class Solution {
public:
    int hIndex(vector<int>& citations) {
        /**
         * Problem: 0274 - H-Index
         * 
         * Find the h-index: maximum h where at least h papers have h or more citations.
         * 
         * Approach: Counting sort technique. Create buckets for citation counts.
         * Papers with citations >= n are capped at n. Then traverse from high to low,
         * accumulating papers until we find the h-index.
         * 
         * Time complexity: O(n) where n is number of papers.
         * Space complexity: O(n) for the count array.
         */
        
        int n = citations.size();
        
        // Count papers by citation count (capped at n).
        vector<int> count(n + 1, 0);
        for (int c : citations) {
            // Papers with n or more citations go in bucket n.
            count[min(c, n)]++;
        }
        
        // Find h-index by traversing from high to low.
        int papers = 0;
        for (int h = n; h >= 0; h--) {
            papers += count[h];
            // Found h papers with at least h citations.
            if (papers >= h) {
                return h;
            }
        }
        
        return 0;
    }
};
