class Solution {
public:
    /*
    Problem: 0074 - Search a 2D Matrix

    You are given a 2D matrix with rows sorted in increasing order and
    each row's first element greater than the last of the previous row.
    Determine if a target value exists in the matrix.

    Approach:
    - Use binary search over a virtual 1D array of length m * n.
    - Convert the 1D index mid into 2D indices: row = mid / n, col = mid % n.
    - Compare the matrix value at that position to the target.

    Time Complexity: O(log(m * n)), where m = matrix height, n = matrix width.
    Space Complexity: O(1).
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;  // Edge case: empty matrix.
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        // Perform binary search over the virtual flattened array.
        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = matrix[row][col];

            if (val == target) {
                return true;  // Target found.
            } else if (val < target) {
                left = mid + 1;  // Search in the right half.
            } else {
                right = mid - 1;  // Search in the left half.
            }
        }

        return false;  // Target not found.
    }
};

