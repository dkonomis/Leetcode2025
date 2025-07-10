class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        Problem: 0088 - Merge Sorted Array

        You are given two sorted arrays nums1 and nums2, and integers m and n.
        Merge nums2 into nums1 in-place to form a single sorted array.

        Approach:
        - Use three pointers starting from the back:
            p1 = m - 1 (end of nums1's valid portion),
            p2 = n - 1 (end of nums2),
            p = m + n - 1 (end of total allocated space in nums1).
        - At each step, compare nums1[p1] and nums2[p2], and insert the larger.
        - If nums2 has remaining elements, copy them into nums1.

        Time complexity: O(m + n)
        Space complexity: O(1)
        */

        int p1 = m - 1;            // Pointer to end of nums1's initial part.
        int p2 = n - 1;            // Pointer to end of nums2.
        int p = m + n - 1;         // Pointer to place elements at end of nums1.

        // Merge from the back to avoid overwriting values in nums1.
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // Copy remaining elements from nums2, if any.
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};

