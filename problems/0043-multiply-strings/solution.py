class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
        0043. Multiply Strings

        Problem:
        Given two non-negative integers num1 and num2 represented as strings,
        return their product, also represented as a string.
        No built-in BigInteger conversion or multiplication allowed.

        Approach:
        - Simulate the grade-school multiplication digit by digit.
        - Use an array of size (m + n) to store intermediate results.
        - Multiply digit i of num1 by digit j of num2 and add to position i + j + 1.
        - Handle carry while building the result string.

        Time complexity: O(m * n), where m = len(num1), n = len(num2).
        Each digit in num1 is multiplied with each digit in num2.

        Space complexity: O(m + n) for the result array.
        """

        m, n = len(num1), len(num2)
        res = [0] * (m + n)  # Holds the result digits.

        # Reverse iterate over digits of num1 and num2.
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                # Multiply current digits.
                mul = int(num1[i]) * int(num2[j])
                p1, p2 = i + j, i + j + 1

                # Add to previous stored result.
                total = mul + res[p2]

                # Update result array with carry and digit.
                res[p1] += total // 10
                res[p2] = total % 10

        # Skip leading zeros and convert digits to string.
        result = []
        for digit in res:
            if not result and digit == 0:
                continue
            result.append(str(digit))

        return ''.join(result) if result else '0'

