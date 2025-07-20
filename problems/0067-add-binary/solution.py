class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        Problem: 0067 - Add Binary

        Given two binary strings a and b, return their sum as a binary string.

        Approach:
        - Use two pointers starting from the end of both strings.
        - Add digits from both strings along with carry.
        - Append the result of each bit to a list and reverse it at the end.
        - If carry remains, append '1' to the front.

        Time complexity: O(max(n, m)), where n = len(a), m = len(b)
        Space complexity: O(max(n, m))
        """
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        res = []

        # Traverse both strings from right to left while there's input or carry left.
        while i >= 0 or j >= 0 or carry:
            bit_a = int(a[i]) if i >= 0 else 0
            bit_b = int(b[j]) if j >= 0 else 0

            total = bit_a + bit_b + carry
            res.append(str(total % 2))      # Append current bit.
            carry = total // 2              # Update carry.

            i -= 1
            j -= 1

        return ''.join(reversed(res))

