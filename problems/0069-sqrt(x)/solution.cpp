class Solution {
public:
    /*
    Problem: 0069 - Sqrt(x)

    Given a non-negative integer x, compute and return the square root of x,
    rounded down to the nearest integer.

    Approach:
    - Use binary search to find the largest integer whose square is ≤ x.
    - Search range is from 0 to x.
    - If mid² ≤ x and (mid + 1)² > x, then mid is the correct answer.

    Time Complexity: O(log x)
    Space Complexity: O(1)
    */
    int mySqrt(int x) {
        if (x < 2) {
            return x;  // Quick return for 0 or 1.
        }

        int left = 1, right = x;

        // Perform binary search for floor(sqrt(x)).
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long squared = 1LL * mid * mid;  // Prevent overflow.

            if (squared == x) {
                return mid;  // Perfect square found.
            } else if (squared < x) {
                left = mid + 1;  // Try a larger candidate.
            } else {
                right = mid - 1;  // Try a smaller candidate.
            }
        }

        // Right will point to floor(sqrt(x)) at the end.
        return right;

