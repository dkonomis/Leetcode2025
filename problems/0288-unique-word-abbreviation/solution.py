class ValidWordAbbr:

    def __init__(self, dictionary: List[str]):
        """
        Problem: 0288 - Unique Word Abbreviation
        
        Design a data structure to check if a word's abbreviation is unique
        in a dictionary. An abbreviation is unique if no other word shares
        the same abbreviation, or if all words with that abbreviation are
        the same word.
        
        Approach:
        - Map each abbreviation to a set of words that have it
        - For uniqueness check: abbreviation doesn't exist OR 
          only contains the query word
        
        Time complexity: O(n) for initialization where n is dictionary size.
        Space complexity: O(n) to store abbreviation mappings.
        """
        self.abbr_map = {}
        
        # Build abbreviation map.
        for word in dictionary:
            abbr = self.get_abbreviation(word)
            if abbr not in self.abbr_map:
                self.abbr_map[abbr] = set()
            self.abbr_map[abbr].add(word)
    
    def get_abbreviation(self, word: str) -> str:
        # Words with length <= 2 have no abbreviation.
        if len(word) <= 2:
            return word
        # Format: first_letter + middle_length + last_letter.
        return word[0] + str(len(word) - 2) + word[-1]

    def isUnique(self, word: str) -> bool:
        """
        Check if word's abbreviation is unique.
        Returns true if:
        1. No word in dictionary has this abbreviation, OR
        2. All words with this abbreviation are the same as query word
        
        Time complexity: O(1) for lookup.
        Space complexity: O(1) for the check.
        """
        abbr = self.get_abbreviation(word)
        
        # Case 1: Abbreviation not in dictionary.
        if abbr not in self.abbr_map:
            return True
        
        # Case 2: Check if all words with this abbr are the same as word.
        # This is true when the set contains only the query word.
        return len(self.abbr_map[abbr]) == 1 and word in self.abbr_map[abbr]


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
