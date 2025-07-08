class Solution:
    def myPow(self, x: float, n: int) -> float:
        """
        50. Pow(x, n)

        Summary:
        Compute x raised to the power n (i.e., xⁿ), handling both positive and negative exponents.
        Use fast exponentiation (a.k.a. binary exponentiation) to reduce time complexity.

        Approach:
        - For n < 0, compute the reciprocal of x^(-n).
        - Use iterative fast exponentiation:
            - If n is odd, multiply result by x.
            - Square x and halve n at each step.
        - Continue until n becomes 0.

        Time complexity: O(log |n|)  
        Space complexity: O(1)
        """
        if n == 0:
            return 1.0  # x⁰ = 1 for any x.

        negative = n < 0  # track if exponent is negative.
        n = abs(n)

        res = 1.0  # initialize result.
        while n > 0:
            if n % 2 == 1:
                res *= x  # apply current base when exponent is odd.
            x *= x  # square the base.
            n //= 2  # halve the exponent.

        return 1 / res if negative else res  # invert if originally negative.

