#include <vector>
using namespace std;

class Solution {
public:
    /*
    Problem: 0066 - Plus One

    Given a non-empty array of decimal digits representing a non-negative integer,
    increment the integer by one and return the resulting array of digits.

    Approach:
    - Start from the least significant digit (rightmost).
    - If the digit is less than 9, increment it and return.
    - If the digit is 9, set it to 0 and carry 1 to the next digit.
    - After the loop, if we still have a carry, insert 1 at the front.

    Time Complexity: O(n), where n is the number of digits.
    Space Complexity: O(1) extra space (in-place), O(n) for the output vector.
    */
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse digits from right to left.
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;  // No carry needed.
                return digits;
            }
            digits[i] = 0;  // Carry over to the next digit.
        }

        // All digits were 9. Insert 1 at the front.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

