#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers at the beginning and end of the array.
        int left = 0;
        int right = height.size() - 1;

        // Variable to store the maximum area found.
        int max_area = 0;

        // Move the pointers toward each other.
        while (left < right) {
            // Compute the current height and width.
            int current_height = min(height[left], height[right]);
            int width = right - left;

            // Compute the current area.
            int current_area = current_height * width;

            // Update the maximum area if the current one is greater.
            if (current_area > max_area) {
                max_area = current_area;
            }

            // Move the pointer pointing to the shorter line inward.
            // This is because the height is limited by the shorter line,
            // and we want to try a taller line to potentially increase the area.
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        // Return the maximum area found.
        return max_area;
    }
};

