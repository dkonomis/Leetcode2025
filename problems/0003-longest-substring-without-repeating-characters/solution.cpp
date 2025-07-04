#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        Problem: 0003 - Longest Substring Without Repeating Characters.

        Given a string, return the length of the longest substring without repeating characters.

        Approach:
        - Use a sliding window with two pointers: left and right.
        - Use an unordered_set to track characters currently in the window.
        - Expand the right pointer on each iteration.
        - If a duplicate character is found, shrink the window from the left
          until all characters are unique again.
        - Track and update the max window length.

        Time Complexity: O(n), where n is the length of the string.
        Space Complexity: O(min(n, m)), where m is the charset size.
        */

        unordered_set<char> seen;   // Set of unique characters in the window.
        int left = 0, max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            // While current character is a duplicate, shrink from the left.
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);   // Remove leftmost character.
                ++left;                // Move left pointer forward.
            }

            seen.insert(s[right]);     // Add new character to window.
            max_len = max(max_len, right - left + 1);  // Update max length.
        }

        return max_len;
    }
};

