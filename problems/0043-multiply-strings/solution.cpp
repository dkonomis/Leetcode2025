// 0043. Multiply Strings

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        /*
        0043. Multiply Strings

        Problem:
        Multiply two non-negative integers given as strings and return the product as a string.
        No built-in BigInteger operations or direct conversion allowed.

        Approach:
        - Simulate the grade-school multiplication algorithm.
        - Create an integer array of size m + n to store intermediate results.
        - For each digit pair (i, j), multiply num1[i] * num2[j] and add it to res[i + j + 1].
        - Carry is managed by distributing values between res[i + j] and res[i + j + 1].

        Time complexity: O(m * n), where m = num1.length(), n = num2.length().
        Space complexity: O(m + n), for the result array.
        */

        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);  // Holds the result digits.

        // Multiply each digit pair from right to left.
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');  // Digit multiplication.
                int p1 = i + j;
                int p2 = i + j + 1;

                int total = mul + res[p2];  // Add to the current value.

                res[p1] += total / 10;      // Carry to higher position.
                res[p2] = total % 10;       // Current digit.
            }
        }

        // Convert result vector to string, skipping leading zeros.
        string result;
        for (int digit : res) {
            if (result.empty() && digit == 0) continue;
            res += to_string(digit);
        }

        return result.empty() ? "0" : result;
    }
};

