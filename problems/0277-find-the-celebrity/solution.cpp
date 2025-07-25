/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        /**
         * Problem: 0277 - Find the Celebrity
         * 
         * Find the celebrity using two-pass elimination. First pass narrows
         * down to one candidate. Second pass verifies if this candidate is
         * truly a celebrity. Key insight: if A knows B, then A cannot be
         * celebrity; if A doesn't know B, then B cannot be celebrity.
         * 
         * Time complexity: O(n).
         * Space complexity: O(1).
         */
        
        // First pass: find the candidate.
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                // If candidate knows i, candidate can't be celebrity.
                candidate = i;
            }
        }
        
        // Second pass: verify the candidate.
        for (int i = 0; i < n; i++) {
            if (i == candidate) {
                continue;
            }
            
            // Celebrity should not know anyone and everyone should know celebrity.
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
        
        int res = candidate;
        return res;
    }
};
