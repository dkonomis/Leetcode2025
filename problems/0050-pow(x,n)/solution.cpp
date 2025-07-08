#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        /*
        50. Pow(x, n)

        Summary:
        Compute x raised to the power n (i.e., xⁿ), handling both positive and negative exponents.
        Use fast exponentiation (binary exponentiation) to reduce time complexity.

        Approach:
        - For n < 0, compute the reciprocal of x^(-n).
        - Use iterative fast exponentiation:
            - If n is odd, multiply result by x.
            - Square x and halve n at each step.
        - Continue until n becomes 0.

        Time complexity: O(log |n|)
        Space complexity: O(1)
        */

        long long exp = n;  // use long long to safely handle INT_MIN.
        bool negative = exp < 0;
        exp = abs(exp);

        double res = 1.0;

        while (exp > 0) {
            if (exp % 2 == 1) {
                res *= x;  // apply current base when exponent is odd.
            }
            x *= x;       // square the base.
            exp /= 2;     // halve the exponent.
        }

        return negative ? 1.0 / res : res;  // invert if originally negative.
    }
};

