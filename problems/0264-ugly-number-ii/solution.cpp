class Solution {
public:
    int nthUglyNumber(int n) {
        /**
         * Problem: 0264 - Ugly Number II
         * 
         * Find the nth ugly number where ugly numbers have only 2, 3, 5 as prime factors.
         * 
         * Approach: Dynamic programming with three pointers. Maintain an array of ugly numbers
         * and use three pointers to track positions for multiplying by 2, 3, and 5. At each
         * step, choose the minimum of the three candidates and advance the corresponding pointer(s).
         * 
         * Time complexity: O(n).
         * Space complexity: O(n).
         */
        
        // Initialize array to store ugly numbers.
        vector<int> ugly(n);
        ugly[0] = 1;
        
        // Three pointers for multiples of 2, 3, and 5.
        int i2 = 0, i3 = 0, i5 = 0;
        
        // Generate ugly numbers from index 1 to n-1.
        for (int i = 1; i < n; i++) {
            // Calculate next candidates.
            int next_multiple_of_2 = ugly[i2] * 2;
            int next_multiple_of_3 = ugly[i3] * 3;
            int next_multiple_of_5 = ugly[i5] * 5;
            
            // Choose the minimum as the next ugly number.
            ugly[i] = min({next_multiple_of_2, next_multiple_of_3, next_multiple_of_5});
            
            // Move pointer(s) forward if their value was chosen.
            if (ugly[i] == next_multiple_of_2) {
                i2++;
            }
            if (ugly[i] == next_multiple_of_3) {
                i3++;
            }
            if (ugly[i] == next_multiple_of_5) {
                i5++;
            }
        }
        
        // Return the nth ugly number.
        return ugly[n - 1];
    }
};
