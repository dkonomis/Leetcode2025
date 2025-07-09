class Solution {
public:
    /*
    Problem: 0075 - Sort Colors

    Given an array nums with 0s, 1s, and 2s representing red, white, and blue,
    sort them in-place so that objects of the same color are adjacent and ordered
    as 0, then 1, then 2.

    Approach:
    - Use the Dutch National Flag algorithm.
    - Maintain three pointers:
        - left: boundary between 0s and 1s.
        - right: boundary between 2s and unknowns.
        - mid: current index to examine.
    - Swap 0s to the front, 2s to the back, and leave 1s in place.

    Time Complexity: O(n), where n is the size of nums.
    Space Complexity: O(1).
    */
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;

        // Process elements until mid passes the right boundary.
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[left]);  // Move 0 to the front.
                ++left;
                ++mid;
            } else if (nums[mid] == 1) {
                ++mid;  // Leave 1 in place.
            } else {
                swap(nums[mid], nums[right]);  // Move 2 to the back.
                --right;  // Re-check the swapped-in value.
            }
        }
    }
};

