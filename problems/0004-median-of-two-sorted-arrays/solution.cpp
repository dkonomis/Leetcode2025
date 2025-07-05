#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        Problem: 0004 - Median of Two Sorted Arrays.

        Given two sorted arrays, return their median in O(log(min(m, n))) time.

        Time Complexity: O(log(min(m, n))).
        Space Complexity: O(1).
        */

        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if (A.size() > B.size()) swap(A, B);  // Always binary search the smaller array.

        int m = A.size();
        int n = B.size();
        int total = m + n;
        int half = total / 2;

        int left = 0, right = m;
        while (left <= right) {
            int pA = (left + right) / 2;  // Partition index for A.
            int pB = half - pA;           // Complement partition index for B.

            // Handle boundaries by using sentinel values.
            int Aleft  = (pA > 0) ? A[pA - 1] : INT_MIN;
            int Aright = (pA < m) ? A[pA]     : INT_MAX;
            int Bleft  = (pB > 0) ? B[pB - 1] : INT_MIN;
            int Bright = (pB < n) ? B[pB]     : INT_MAX;

            // Check if partition is valid.
            if (Aleft <= Bright && Bleft <= Aright) {
                // If total number of elements is odd, return the middle element.
                if (total % 2 == 1) {
                    return min(Aright, Bright);
                }
                // If even, return the average of the two middle values.
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                // Partition A is too far right — Aleft is too large to be in the left half.
                // Move the search range to the left.
                right = pA - 1;
            } else {
                // Partition A is too far left — Aright is too small to separate left and right halves.
                // Move the search range to the right.
                left = pA + 1;
            }
        }

        throw runtime_error("Input arrays are not sorted properly.");
    }
};

