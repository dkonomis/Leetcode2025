#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
        0028. Find the Index of the First Occurrence in a String

        Problem:
        Given two strings haystack and needle, return the index of the first occurrence of needle in haystack,
        or -1 if needle is not part of haystack.

        Approach:
        Use a sliding window to compare substrings of haystack with needle.
        For each index i in haystack, check if the substring starting at i matches needle character by character
        using an inner loop with index j. If a full match is found, return i.

        Time Complexity: O(n * m), where n is the length of haystack and m is the length of needle.
        Space Complexity: O(1), constant extra space.
        */

        int n = haystack.size();
        int m = needle.size();

        if (m == 0) {
            return 0;  // Empty needle matches at index 0.
        }

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;  // Found a full match.
            }
        }

        return -1;  // No match found.
    }
};

