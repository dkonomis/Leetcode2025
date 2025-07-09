class Solution {
public:
    /*
    Problem: 0080 - Remove Duplicates from Sorted Array II

    Given a sorted array, remove duplicates in-place such that each unique element
    appears at most twice. Return the length of the modified array.

    Approach:
    - Use a two-pointer technique.
    - Keep a write pointer that only advances when an element is allowed.
    - Allow up to two occurrences of each unique value.
    - Compare with the value two positions before the current write index.

    Time Complexity: O(n), where n is the length of the input array.
    Space Complexity: O(1), in-place modification.
    */
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int write = 2;  // Start writing from index 2.

        // Iterate through the array starting from index 2.
        for (int read = 2; read < nums.size(); ++read) {
            // Only write if current value is not the same as the value two positions back.
            if (nums[read] != nums[write - 2]) {
                nums[write] = nums[read];  // Overwrite the write index with the read value.
                ++write;  // Move the write pointer forward.
            }
        }

        return write;
    }
};

