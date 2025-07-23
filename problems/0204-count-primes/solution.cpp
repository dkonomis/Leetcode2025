class Solution {
public:
    int countPrimes(int n) {
        /*
         * Problem: 0204 - Count Primes
         * Given integer n, return the number of prime numbers that are strictly less than n.
         * A prime number has exactly two factors: 1 and itself.
         * 
         * Approach: Use Sieve of Eratosthenes algorithm. Mark all composite numbers
         * by iterating through multiples of each prime, then count remaining primes.
         * 
         * Time complexity: O(n log log n).
         * Space complexity: O(n) for the boolean array.
         */
        
        if (n <= 2) {
            return 0;
        }
        
        // Initialize boolean array - true means potentially prime.
        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime.
        
        // Sieve of Eratosthenes algorithm.
        for (int i = 2; i <= sqrt(n); i++) {
            if (is_prime[i]) {
                // Mark all multiples of i as composite (not prime).
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        
        // Count remaining true values (primes).
        int count = 0;
        for (bool prime : is_prime) {
            if (prime) {
                count++;
            }
        }
        
        return count;
    }
};
