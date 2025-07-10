class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Problem: 0088 - Merge Sorted Array

        You are given two sorted arrays nums1 and nums2, and integers m and n.
        Merge nums2 into nums1 in-place to form a single sorted array.

        Approach:
        - Start filling nums1 from the back, using three pointers:
            p1 = m - 1 (end of initial nums1),
            p2 = n - 1 (end of nums2),
            p = m + n - 1 (end of total space in nums1).
        - Compare elements from the back and insert the larger one.
        - If elements remain in nums2, copy them into nums1.

        Time complexity: O(m + n)
        Space complexity: O(1)
        """

        p1 = m - 1  # Pointer to end of nums1's initial part.
        p2 = n - 1  # Pointer to end of nums2.
        p = m + n - 1  # Pointer to fill from the back of nums1.

        # Merge nums2 into nums1 starting from the end.
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1

        # If there are remaining elements in nums2, copy them.
        while p2 >= 0:
            nums1[p] = nums2[p2]
            p2 -= 1
            p -= 1

