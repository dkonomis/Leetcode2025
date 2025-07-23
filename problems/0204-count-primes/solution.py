class Solution:
    def countPrimes(self, n: int) -> int:
        """
        Problem: 0204 - Count Primes
        
        Given integer n, return the number of prime numbers that are strictly less than n.
        A prime number has exactly two factors: 1 and itself.
        
        Approach: Use Sieve of Eratosthenes algorithm. Mark all composite numbers
        by iterating through multiples of each prime, then count remaining primes.
        
        Time complexity: O(n log log n).
        Space complexity: O(n) for the boolean array.
        """
        import math
        
        if n <= 2:
            return 0
        
        # Initialize boolean array - True means potentially prime.
        is_prime = [True] * n
        is_prime[0] = is_prime[1] = False  # 0 and 1 are not prime.
        
        # Sieve of Eratosthenes algorithm.
        for i in range(2, int(math.sqrt(n)) + 1):
            if is_prime[i]:
                # Mark all multiples of i as composite (not prime).
                for j in range(i * i, n, i):
                    is_prime[j] = False
        
        # Count remaining True values (primes).
        return sum(is_prime)
