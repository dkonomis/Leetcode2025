#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    Problem: 0067 - Add Binary

    Given two binary strings a and b, return their sum as a binary string.

    Approach:
    - Use two pointers starting from the end of both strings.
    - At each step, add the corresponding bits and carry.
    - Append the result bit to the result string.
    - If any carry remains at the end, append '1'.
    - Reverse the final string to get the correct result.

    Time Complexity: O(max(n, m)), where n = a.length(), m = b.length()
    Space Complexity: O(max(n, m))
    */
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res;

        // Traverse both strings from right to left while input or carry remains.
        while (i >= 0 || j >= 0 || carry) {
            int bit_a = (i >= 0 && a[i] == '1') ? 1 : 0;
            int bit_b = (j >= 0 && b[j] == '1') ? 1 : 0;

            int total = bit_a + bit_b + carry;
            res += (total % 2) ? '1' : '0';  // Append result bit.
            carry = total / 2;               // Update carry.

            i--;
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

