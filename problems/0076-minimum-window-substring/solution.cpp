class Solution {
public:
    /*
    Problem: 0076 - Minimum Window Substring

    Given two strings s and t, return the minimum window in s which contains all the characters in t.
    If there is no such window, return the empty string.

    Approach:
    - Use the sliding window technique with two pointers (left and right).
    - Count the required frequency of characters in t using an unordered_map.
    - Expand the window by moving right to include more characters.
    - When the window contains all required characters, try to shrink it from the left.
    - Track the smallest valid window found during the process.

    Time Complexity: O(m + n), where m = length of s and n = length of t.
    Space Complexity: O(n) for character counts.
    */
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) {
            return "";  // Edge case: empty input.
        }

        unordered_map<char, int> t_count;
        for (char c : t) {
            t_count[c]++;  // Count required characters from t.
        }

        unordered_map<char, int> window;
        int have = 0;
        int need = t_count.size();

        int res_len = INT_MAX;
        int res_left = 0;
        int left = 0;

        // Expand the window with the right pointer.
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window[c]++;

            // Check if current character meets required frequency.
            if (t_count.count(c) && window[c] == t_count[c]) {
                have++;
            }

            // Shrink the window from the left while it's valid.
            while (have == need) {
                // Update result if the current window is smaller.
                if ((right - left + 1) < res_len) {
                    res_left = left;
                    res_len = right - left + 1;
                }

                // Remove the leftmost character from the window.
                window[s[left]]--;
                if (t_count.count(s[left]) && window[s[left]] < t_count[s[left]]) {
                    have--;  // Lost a required character.
                }
                left++;  // Move left to shrink the window.
            }
        }

        return res_len == INT_MAX ? "" : s.substr(res_left, res_len);
    }
};

