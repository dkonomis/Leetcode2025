class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        """
        Problem 0017 – Letter Combinations of a Phone Number.

        Given a string containing digits from 2 to 9, return all possible letter combinations
        that the number could represent, based on the telephone keypad.

        Return the answer in any order.

        Time Complexity  : O(4^n × n), where n is the length of the input string.
                           Each digit can contribute up to 4 letters, and we build strings of length n.
        Space Complexity : O(n) for recursion, or O(4^n × n) if including output.
        """

        if len(digits) == 0:
            return []

        letters = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }

        def backtrack(idx, path):
            # We have completed a valid combination.
            if len(path) == len(digits):
                combinations.append("".join(path))
                return

            possible_letters = letters[digits[idx]]
            for letter in possible_letters:
                path.append(letter)        # Choose a letter.
                backtrack(idx + 1, path)   # Explore deeper.
                path.pop()                 # Backtrack to try next letter.

        combinations = []
        backtrack(0, [])

        return combinations

