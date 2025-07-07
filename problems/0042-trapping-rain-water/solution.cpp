// 0042. Trapping Rain Water

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        0042. Trapping Rain Water

        Problem:
        Given an array representing an elevation map, compute how much water it can trap after raining.

        Approach:
        - Use two pointers from both ends moving inward.
        - Maintain left_max and right_max as we scan.
        - At each step, trap water depending on the shorter boundary.
        - This avoids precomputing arrays and achieves constant space.

        Time complexity: O(n), where n is the size of height.
        Space complexity: O(1), using only constant extra variables.
        */

        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int res = 0;

        // Continue until the two pointers meet.
        while (left < right) {
            if (height[left] < height[right]) {
                // Current left side is lower — bounded by left_max.
                if (height[left] >= left_max) {
                    // Update left_max if necessary.
                    left_max = height[left];
                } else {
                    // Water trapped at this position.
                    res += left_max - height[left];
                }
                ++left;  // Move left pointer inward.
            } else {
                // Current right side is lower — bounded by right_max.
                if (height[right] >= right_max) {
                    // Update right_max if necessary.
                    right_max = height[right];
                } else {
                    // Water trapped at this position.
                    res += right_max - height[right];
                }
                --right;  // Move right pointer inward.
            }
        }

        return res;
    }
};

