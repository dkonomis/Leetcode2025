class Solution {
public:
    int trailingZeroes(int n) {
        /*
        Problem: 0172 - Factorial Trailing Zeroes
        
        Count trailing zeroes in n! without calculating the factorial.
        Trailing zeroes come from factors of 10 = 2 × 5.
        
        Approach:
        - Since there are always more factors of 2 than 5 in factorial, count factors of 5
        - Count multiples of 5: n//5
        - Count multiples of 25 (contribute extra factor): n//25  
        - Count multiples of 125 (contribute extra factor): n//125
        - Continue until n//5^k = 0
        - Total = n//5 + n//25 + n//125 + ...
        
        Time complexity: O(log n).
        Space complexity: O(1).
        */
        
        int count = 0;
        
        // Count factors of 5 in n!
        // Each power of 5 contributes additional factors.
        while (n > 0) {
            n /= 5;     // Divide by 5 to get multiples of current power of 5.
            count += n; // Add count of multiples.
        }
        
        return count;
    }
};
