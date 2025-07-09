class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
        Problem: 0085 - Maximal Rectangle

        Given a binary matrix filled with '0's and '1's, return the area of the largest rectangle containing only '1's.

        Approach:
        - Treat each row as the base of a histogram.
        - Maintain a histogram height array that tracks the number of consecutive 1s per column.
        - For each row, update the histogram and compute the largest rectangle in that histogram using a monotonic stack.

        Time complexity: O(m × n), where m = number of rows, n = number of columns.
        Space complexity: O(n), for the histogram and stack.
        */

        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);  // Histogram heights.
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            // Update histogram based on current row.
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;  // Extend height.
                } else {
                    heights[j] = 0;  // Reset height.
                }
            }

            // Compute the largest rectangle area in the current histogram.
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        // Standard monotonic increasing stack for 0084 - Largest Rectangle in Histogram.

        heights.push_back(0);  // Append sentinel to flush the stack.
        stack<int> st;         // Stack to store indices of increasing heights.
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            // Pop while the current height is less than the top of the stack.
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;  // No smaller bar to the left.
                } else {
                    width = i - st.top() - 1;  // Width between the next smaller to left and current.
                }

                maxArea = max(maxArea, height * width);  // Update max area.
            }

            st.push(i);  // Push current index to stack.
        }

        heights.pop_back();  // Restore original vector.
        return maxArea;
    }
};

