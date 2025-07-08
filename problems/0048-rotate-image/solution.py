class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        48. Rotate Image

        Summary:
        Rotate an n×n matrix 90° clockwise in-place by rotating each group of 4 cells layer by layer.

        Approach:
        - For each layer from outermost to innermost:
            - For each group of 4 symmetric cells in that layer:
                - Perform 4-way swap among top, left, bottom, right.

        Time complexity: O(n^2)
        Space complexity: O(1)
        """
        n = len(matrix)  # matrix is n x n.
        
        # Process the matrix layer by layer from outer to inner.
        for layer in range(n // 2):
            first = layer
            last = n - 1 - layer  # last index in this layer.
            for i in range(first, last):
                offset = i - first  # distance from the left edge of the layer.
                
                # Save top element before it gets overwritten.
                top = matrix[first][i]
                
                # Move left -> top.
                matrix[first][i] = matrix[last - offset][first]
                
                # Move bottom -> left.
                matrix[last - offset][first] = matrix[last][last - offset]
                
                # Move right -> bottom.
                matrix[last][last - offset] = matrix[i][last]
                
                # Move top -> right.
                matrix[i][last] = top

