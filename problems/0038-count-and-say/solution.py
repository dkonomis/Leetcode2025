class Solution:
    def countAndSay(self, n: int) -> str:
        """
        0038. Count and Say

        Given an integer n, return the nth term of the count-and-say sequence.

        Approach:
        Build the sequence iteratively starting from "1". For each term, read the previous term,
        group consecutive identical digits, and describe them as "<count><digit>" strings.

        Time complexity: O(4^{n/3}).
        The length of the i-th term is bounded by O(4^{i/3}), so the total
        work up to n is O(4^{n/3}).

        Space complexity: O(4^{n/3}), the length of the n-th term.
        """

        res = "1"  # Base case: countAndSay(1) = "1"

        for _ in range(n - 1):
            i = 0
            curr = ""

            while i < len(res):
                count = 1

                # Count how many times the current digit repeats consecutively.
                while i + 1 < len(res) and res[i] == res[i + 1]:
                    i += 1
                    count += 1

                # Append the count followed by the digit.
                curr += str(count) + res[i]
                i += 1

            res = curr  # Move to the next term in the sequence.

        return res

