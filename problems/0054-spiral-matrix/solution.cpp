#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
        54. Spiral Matrix

        Summary:
        Traverse a 2D matrix in spiral order and return the resulting list.

        Approach:
        - Use four boundaries: top, bottom, left, right.
        - Repeatedly traverse the edges of the current "layer":
            - From left to right across the top.
            - From top to bottom down the right.
            - From right to left across the bottom (if still valid).
            - From bottom to top up the left (if still valid).
        - After each pass, shrink the boundaries inward.

        Time complexity: O(m * n), where m and n are matrix dimensions.
        Space complexity: O(1) extra (excluding output).
        */
        vector<int> res;  // final spiral order list.
        if (matrix.empty() || matrix[0].empty()) return res;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row.
            for (int col = left; col <= right; ++col) {
                res.push_back(matrix[top][col]);
            }
            ++top;  // move top boundary down.

            // Traverse from top to bottom down the right column.
            for (int row = top; row <= bottom; ++row) {
                res.push_back(matrix[row][right]);
            }
            --right;  // move right boundary left.

            // Traverse from right to left along the bottom row.
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    res.push_back(matrix[bottom][col]);
                }
                --bottom;  // move bottom boundary up.
            }

            // Traverse from bottom to top up the left column.
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    res.push_back(matrix[row][left]);
                }
                ++left;  // move left boundary right.
            }
        }

        return res;
    }
};

