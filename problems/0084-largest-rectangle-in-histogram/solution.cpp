class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        Problem: 0084 - Largest Rectangle in Histogram

        Given an array of integers representing bar heights in a histogram,
        return the area of the largest rectangle that can be formed.

        Approach:
        - Use a monotonic increasing stack to track indices of bars.
        - Append a sentinel height 0 at the end to flush the stack.
        - For each bar, while the current height is smaller than the height at the top of the stack,
          pop the stack and compute the area of the rectangle with the popped height.
        - Width is computed based on the current index and the new top of the stack.

        Time complexity: O(n), where n is the number of bars.
        Space complexity: O(n)
        */

        heights.push_back(0);  // Append sentinel to flush the stack at the end.
        stack<int> st;         // Stack to store indices of increasing heights.
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            // While the current height breaks the increasing order of the stack.
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                // Compute the width of the rectangle.
                int width;
                if (st.empty()) {
                    // No smaller height to the left, so extend all the way to index 0.
                    width = i;
                } else {
                    // Width spans from st.top() + 1 to i - 1.
                    width = i - st.top() - 1;
                }

                // Compute and update maximum area.
                maxArea = max(maxArea, height * width);
            }

            // Push the current index to the stack.
            st.push(i);
        }

        return maxArea;
    }
};

