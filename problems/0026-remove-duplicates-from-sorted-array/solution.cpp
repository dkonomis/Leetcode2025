#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        0026. Remove Duplicates from Sorted Array

        Problem:
        Given a sorted integer array nums, remove the duplicates in-place such that each unique element appears only once.
        The relative order of the elements should be preserved.
        You must return the number of unique elements, k, and modify the input array so that the first k elements are the result.
        The rest of the array beyond index k can contain any values.

        Approach:
        Use two pointers:
            - One pointer (write) tracks the index to write the next unique element.
            - The other pointer (read) scans forward through the array.
        For each element, if it is different from the previous one, write it forward and advance write.
        This works in-place since the array is already sorted.

        Time Complexity: O(n), where n is the length of the array.
        Space Complexity: O(1), constant extra space.
        */

        if (nums.empty()) {
            return 0;
        }

        int write = 1;
        for (int read = 1; read < nums.size(); read++) {
            if (nums[read] != nums[read - 1]) {
                nums[write] = nums[read];
                write++;
            }
        }

        return write;
    }
};

