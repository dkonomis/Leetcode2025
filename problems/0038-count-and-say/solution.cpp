class Solution {
public:
    string countAndSay(int n) {
        /*
        0038. Count and Say

        Given an integer n, return the nth term of the count-and-say sequence.

        Approach:
        Start from "1" and iteratively build the sequence up to the nth term.
        For each term, read the previous term digit by digit, grouping identical digits together,
        and for each group output "<count><digit>".

        Time complexity: O(4^{n/3}).
        The length of the i-th term is bounded by O(4^{i/3}), so the total
        work up to n is O(4^{n/3}).

        Space complexity: O(4^{n/3}), the length of the n-th term.
        */

        string res = "1";  // Base case: countAndSay(1) = "1"

        for (int step = 1; step < n; ++step) {
            string curr = "";
            int i = 0;

            while (i < res.size()) {
                int count = 1;

                // Count how many times the current digit repeats consecutively.
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++i;
                    ++count;
                }

                // Append the count followed by the digit.
                curr += to_string(count) + res[i];
                ++i;
            }

            res = curr;  // Prepare for the next iteration.
        }

        return res;
    }
};

