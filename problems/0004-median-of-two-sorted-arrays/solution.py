from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        Problem: 0004 - Median of Two Sorted Arrays.

        Given two sorted arrays, find their median in O(log(min(m, n))) time.

        Time Complexity: O(log(min(m, n))).
        Space Complexity: O(1).
        """

        A, B = nums1, nums2
        if len(A) > len(B):
            A, B = B, A  # Always binary search the smaller array.

        m, n = len(A), len(B)
        total = m + n
        half = total // 2

        left, right = 0, m
        while left <= right:
            pA = (left + right) // 2  # Partition index in A.
            pB = half - pA            # Partition index in B (complement).

            # Handle out-of-bound values by using ±infinity.
            Aleft = A[pA - 1] if pA > 0 else float('-inf')
            Aright = A[pA] if pA < m else float('inf')
            Bleft = B[pB - 1] if pB > 0 else float('-inf')
            Bright = B[pB] if pB < n else float('inf')

            # Check if the partition is valid.
            if Aleft <= Bright and Bleft <= Aright:
                # Odd total → return the middle value.
                if total % 2:
                    return min(Aright, Bright)
                # Even total → return average of middle two values.
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
            elif Aleft > Bright:
                # Partition A is too far right — shift search window left.
                right = pA - 1
            else:
                # Partition A is too far left — shift search window right.
                left = pA + 1

        raise ValueError("Input arrays are not sorted properly.")

