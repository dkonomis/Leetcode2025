#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
        48. Rotate Image

        Summary:
        Rotate an n×n matrix 90° clockwise in-place by rotating each group of 4 cells layer by layer.

        Approach:
        - For each layer from outermost to innermost:
            - For each group of 4 symmetric cells in that layer:
                - Perform 4-way swap among top, left, bottom, right.

        Time complexity: O(n^2)
        Space complexity: O(1)
        */
        int n = matrix.size();  // matrix is n x n.

        // Process the matrix layer by layer from outer to inner.
        for (int layer = 0; layer < n / 2; ++layer) {
            int first = layer;
            int last = n - 1 - layer;  // last index in this layer.

            for (int i = first; i < last; ++i) {
                int offset = i - first;  // distance from the left edge of the layer.

                // Save the top element before it gets overwritten.
                int top = matrix[first][i];

                // Move left -> top.
                matrix[first][i] = matrix[last - offset][first];

                // Move bottom -> left.
                matrix[last - offset][first] = matrix[last][last - offset];

                // Move right -> bottom.
                matrix[last][last - offset] = matrix[i][last];

                // Move top -> right.
                matrix[i][last] = top;
            }
        }
    }
};

