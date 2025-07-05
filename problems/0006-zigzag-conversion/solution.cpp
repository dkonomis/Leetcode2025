#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /*
        Problem: 0006 - Zigzag Conversion.

        Given a string s and a number of rows, return the string written in a zigzag pattern
        and read line by line.

        Time Complexity: O(n), where n is the length of the string.
        Space Complexity: O(n), for storing the result rows.
        */

        // Edge case: no zigzag needed if one row or fewer characters than rows.
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings to represent each row.
        vector<string> rows(numRows);
        int curr_row = 0;
        bool going_down = false;

        // Iterate through each character in the input string.
        for (char c : s) {
            rows[curr_row] += c;

            // Reverse direction when we hit the top or bottom row.
            if (curr_row == 0 || curr_row == numRows - 1) {
                going_down = !going_down;
            }

            // Move the row pointer accordingly.
            curr_row += going_down ? 1 : -1;
        }

        // Concatenate all rows into a single result string.
        string res;
        for (const string& row : rows) {
            res += row;
        }

        return res;
    }
};

