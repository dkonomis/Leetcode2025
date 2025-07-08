#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /*
        59. Spiral Matrix II

        Summary:
        Generate an n × n matrix filled with numbers from 1 to n^2 in spiral order.

        Approach:
        - Initialize an n x n matrix with 0s.
        - Use four boundaries (top, bottom, left, right) to guide filling in spiral order.
        - At each layer, fill:
            - top row (left to right)
            - right column (top to bottom)
            - bottom row (right to left)
            - left column (bottom to top)
        - Move boundaries inward after each pass.

        Time complexity: O(n^2)
        Space complexity: O(n^2), for the output matrix
        */
        vector<vector<int>> matrix(n, vector<int>(n, 0));  // n x n matrix initialized with 0
        int num = 1;  // current number to fill
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Fill top row from left to right.
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = num++;
            }
            ++top;

            // Fill right column from top to bottom.
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            --right;

            // Fill bottom row from right to left.
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = num++;
                }
                --bottom;
            }

            // Fill left column from bottom to top.
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = num++;
                }
                ++left;
            }
        }

        return matrix;
    }
};

