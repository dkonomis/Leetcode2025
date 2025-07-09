class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        """
        Problem: 0066 - Plus One

        Given a non-empty array of decimal digits representing a non-negative integer,
        increment the integer by one and return the resulting array of digits.

        Approach:
        - Start from the least significant digit and move left.
        - Add 1 to the last digit. If it becomes 10, set to 0 and carry the 1.
        - Repeat until no carry remains or we process all digits.
        - If carry remains at the end, insert 1 at the beginning.

        Time complexity: O(n), where n is the number of digits.
        Space complexity: O(1) extra space (in-place), O(n) for the output list.
        """
        n = len(digits)

        for i in range(n - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1  # Simple case: just increment and return.
                return digits
            digits[i] = 0  # Set current digit to 0 and continue carry.

        # If loop finishes, all digits were 9. Add extra 1 at the beginning.
        return [1] + digits

