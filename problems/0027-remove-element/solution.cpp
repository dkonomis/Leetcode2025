#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
        0027. Remove Element

        Problem:
        Given an integer array nums and an integer val, remove all occurrences of val in-place.
        Return the number of elements that are not equal to val.
        The order of elements may change, and elements beyond the returned length do not matter.

        Approach:
        Use a write pointer to track the next position to place a non-val element.
        Iterate through the array using a read pointer.
        If nums[read] is not equal to val, write it to nums[write] and advance write.
        At the end, the first write elements are the ones to keep.

        Time Complexity: O(n), where n is the size of the array.
        Space Complexity: O(1), constant extra memory.
        */

        int write = 0;

        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != val) {
                nums[write] = nums[read];
                write++;
            }
        }

        return write;
    }
};

