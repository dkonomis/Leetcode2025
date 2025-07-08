from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        """
        49. Group Anagrams

        Summary:
        Group all strings that are anagrams into separate lists. Two words are anagrams
        if they contain the same letters in any order (with same counts).

        Approach:
        - Use a hash map (defaultdict) to group words by their sorted character tuple.
        - The sorted tuple of characters acts as a canonical form for each anagram group.
        - Append each word to the corresponding group in the map.
        - Return the grouped anagram lists.

        Time complexity: O(N * K * logK), where N is the number of words and K is the maximum length of a word.
        Space complexity: O(N * K), for storing the grouped anagrams.
        """
        anagram_map = defaultdict(list)  # maps sorted char tuple → list of words.

        for word in strs:
            key = tuple(sorted(word))  # canonical form of the word.
            anagram_map[key].append(word)  # group anagrams together.

        return list(anagram_map.values())  # extract all groups.

