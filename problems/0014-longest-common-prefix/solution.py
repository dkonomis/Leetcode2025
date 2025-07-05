class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        """
        Problem 0014 – Longest Common Prefix.

        Write a function to find the longest common prefix string amongst an array of strings.

        If there is no common prefix, return an empty string "".

        Time Complexity  : O(n × m), where n = number of strings and m = average length.
        Space Complexity : O(1) additional space (not counting the output string).
        """

        if not strs:
            return ""  # No strings provided.

        # Take the first string as a starting point.
        prefix = strs[0]

        # Compare the prefix with each string in the list.
        for s in strs[1:]:
            # Shorten the prefix until it matches the beginning of s.
            while not s.startswith(prefix):
                prefix = prefix[:-1]  # Remove the last character.
                if not prefix:
                    return ""  # No common prefix found.

        return prefix  # Return the longest common prefix found.

