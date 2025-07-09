class Solution {
public:
    /*
    Problem: 0070 - Climbing Stairs

    You are climbing a staircase. Each time you can climb 1 or 2 steps.
    Return the number of distinct ways to reach the top.

    Approach:
    - This is equivalent to computing the nth Fibonacci number.
    - Let f(n) = f(n-1) + f(n-2), where:
        - f(1) = 1 (one way to climb 1 step)
        - f(2) = 2 (two ways to climb 2 steps)
    - Use an iterative approach with two variables.

    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int climbStairs(int n) {
        if (n <= 2) {
            return n;  // Base cases: 1 step → 1 way, 2 steps → 2 ways.
        }

        int a = 1;  // Ways to reach step 1
        int b = 2;  // Ways to reach step 2

        // Compute ways from step 3 up to n
        for (int i = 3; i <= n; ++i) {
            int temp = b;
            b = a + b;  // Current ways = sum of previous two
            a = temp;   // Slide the window forward
        }

        return b;
    }
};

