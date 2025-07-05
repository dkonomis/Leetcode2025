#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        /*
        Problem 0014 – Longest Common Prefix.

        Write a function to find the longest common prefix string amongst an array of strings.

        If there is no common prefix, return an empty string "".

        Time Complexity  : O(n × m), where n = number of strings and m = average length.
        Space Complexity : O(1) additional space (excluding the output string).
        */

        if (strs.empty()) {
            return "";  // No strings provided.
        }

        std::string prefix = strs[0];  // Start with the first string as the prefix.

        // Iterate over each string in the array.
        for (size_t i = 1; i < strs.size(); ++i) {
            const std::string& s = strs[i];

            // While the current string does not start with the prefix, shorten it.
            while (s.find(prefix) != 0) {
                prefix.pop_back();  // Remove the last character.
                if (prefix.empty()) {
                    return "";  // No common prefix found.
                }
            }
        }

        return prefix;  // Return the longest common prefix found.
    }
};

