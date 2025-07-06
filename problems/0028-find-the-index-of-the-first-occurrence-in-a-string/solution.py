class Solution:
    """
    0028. Find the Index of the First Occurrence in a String

    Problem:
    Given two strings haystack and needle, return the index of the first occurrence of needle in haystack,
    or -1 if needle is not part of haystack.

    Approach:
    Use a sliding window to compare substrings of haystack to needle.
    For each index i in haystack, check whether the substring haystack[i:i+m] matches needle,
    where m is the length of needle. If it matches, return i. Otherwise, continue.
    Return -1 if no match is found.

    Time Complexity: O(n * m), where n is the length of haystack and m is the length of needle.
    Space Complexity: O(1), constant space used.
    """

    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0  # An empty needle always matches at position 0.

        n = len(haystack)
        m = len(needle)

        # Slide a window of size m over haystack.
        for i in range(n - m + 1):
            j = 0
            # Check if haystack[i:i+m] matches needle.
            while j < m and haystack[i + j] == needle[j]:
                j += 1

            if j == m:
                return i  # Found a full match starting at index i.

        return -1  # No match found.

