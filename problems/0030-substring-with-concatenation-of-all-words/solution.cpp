#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
        0030. Substring with Concatenation of All Words

        Problem:
        Find all starting indices of substrings in s that are concatenations 
        of each word in words exactly once and without intervening characters.

        Approach:
        Use a sliding window of size num_words * word_len.
        For each offset in [0, word_len), slide in word-length steps.
        Maintain a current frequency map and a count of matched words.
        Reset or shrink the window as needed to ensure validity.

        Time complexity: O(a + n⋅b),
        where n = s.length(), a = words.size(), b = words[0].size().

        Space complexity: O(a + b).
        */

        vector<int> res;  // Final result list.

        if (s.empty() || words.empty()) return res;

        int word_len = words[0].size();               // Length of each word.
        int num_words = words.size();                 // Total number of words.
        int total_len = word_len * num_words;         // Total window length.

        unordered_map<string, int> word_count;        // Frequency of required words.
        for (const string& word : words) {
            word_count[word]++;
        }

        // Try each alignment offset in [0, word_len).
        for (int offset = 0; offset < word_len; ++offset) {
            int left = offset;                        // Left pointer of the window.
            int right = offset;                       // Right pointer of the window.
            unordered_map<string, int> current_count; // Current word frequencies.
            int count = 0;                            // Number of valid matches in window.

            while (right + word_len <= s.length()) {
                string word = s.substr(right, word_len);  // Extract current word.
                right += word_len;                        // Move right pointer forward.

                if (word_count.count(word)) {
                    current_count[word]++;                // Add to current window count.

                    if (current_count[word] <= word_count[word]) {
                        count++;                          // Valid match.
                    } else {
                        // Too many of this word — shrink from the left.
                        while (current_count[word] > word_count[word]) {
                            string left_word = s.substr(left, word_len);
                            current_count[left_word]--;
                            if (current_count[left_word] < word_count[left_word]) {
                                count--;                   // Removed a valid match.
                            }
                            left += word_len;              // Slide window left.
                        }
                    }

                    if (count == num_words) {
                        res.push_back(left);              // Found valid start.
                    }
                } else {
                    // Not a valid word — reset state.
                    current_count.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return res;
    }
};

