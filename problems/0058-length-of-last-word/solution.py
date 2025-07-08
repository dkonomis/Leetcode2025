#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        /*
        58. Length of Last Word

        Summary:
        Given a string with words separated by spaces, return the length of the last word.
        A word is defined as a maximal sequence of non-space characters.

        Approach:
        - Skip trailing spaces from the end of the string.
        - Count the characters until the next space or start of the string.
        - Return the count as the length of the last word.

        Time complexity: O(n), where n = s.length()
        Space complexity: O(1)
        */
        int i = s.length() - 1;
        int length = 0;

        // Skip trailing spaces.
        while (i >= 0 && s[i] == ' ') {
            --i;
        }

        // Count characters in the last word.
        while (i >= 0 && s[i] != ' ') {
            ++length;
            --i;
        }

        return length;
    }
};

