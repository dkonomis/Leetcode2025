class Solution:
    def intToRoman(self, num: int) -> str:
        """
        Problem 0012 – Integer to Roman.

        Given an integer between 1 and 3999, convert it to a Roman numeral.

        Roman numeral symbols:
            I = 1, V = 5, X = 10, L = 50,
            C = 100, D = 500, M = 1000

        Subtractive forms are used for:
            4   → IV
            9   → IX
            40  → XL
            90  → XC
            400 → CD
            900 → CM

        Rules:
        - Only I, X, C, M can be repeated (up to 3 times).
        - V, L, D cannot be repeated.
        - Subtractive forms are used instead of 4-symbol repetition.

        Approach:
        Use a greedy algorithm with a descending list of (value, symbol) pairs.
        At each step, subtract the largest possible value from `num` and append the symbol.

        Time Complexity  : O(1)
        Space Complexity : O(1)
        """

        # List of (value, symbol) pairs ordered from largest to smallest,
        # including subtractive combinations like 900 → "CM", 4 → "IV", etc.
        val_to_sym = [
            (1000, 'M'), (900, 'CM'),
            (500, 'D'),  (400, 'CD'),
            (100, 'C'),  (90, 'XC'),
            (50, 'L'),   (40, 'XL'),
            (10, 'X'),   (9, 'IX'),
            (5, 'V'),    (4, 'IV'),
            (1, 'I')
        ]

        res = []  # List to collect Roman numeral parts.

        # Iterate through the value-symbol pairs greedily.
        for value, symbol in val_to_sym:
            count, num = divmod(num, value)   # Determine how many times value fits into num.
            res.append(symbol * count)        # Append that many copies of the symbol.
            if num == 0:
                break                         # Early exit if num is fully converted.

        # Join all parts into a single Roman numeral string.
        return ''.join(res)

