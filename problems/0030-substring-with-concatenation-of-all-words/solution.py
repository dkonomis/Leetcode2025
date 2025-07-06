from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        """
        0030. Substring with Concatenation of All Words

        Problem:
        Find all starting indices of substring(s) in s that is a concatenation 
        of each word in words exactly once, in any order, and without any intervening characters.

        Approach:
        Use a sliding window of size len(words) * len(word). 
        For each offset in range(0, word_len), move the window in steps of word_len,
        counting valid words and checking against the expected frequency map.

        Time complexity: O(a + n⋅b), 
        where n = len(s), a = len(words), and b = len(words[0]).

        Space complexity: O(a + b).
        """
        if not s or not words:
            return []

        word_len = len(words[0])                        # All words are the same length.
        num_words = len(words)                          # Total number of words.
        total_len = word_len * num_words                # Total length of concatenated block.
        word_count = Counter(words)                     # Frequency of words needed.
        res = []                                        # Final result list.

        for offset in range(word_len):
            left = offset                               # Left pointer of the window.
            right = offset                              # Right pointer of the window.
            current_count = Counter()                   # Current frequency in window.
            count = 0                                   # Number of valid words matched.

            while right + word_len <= len(s):
                word = s[right:right + word_len]        # Extract current word.
                right += word_len                       # Move right pointer forward.

                if word in word_count:
                    current_count[word] += 1            # Increment count of current word.

                    if current_count[word] <= word_count[word]:
                        count += 1                      # Count this as a valid match.
                    else:
                        # The current word appears more than allowed.
                        # Shrink the window from the left until the word's count is valid again.
                        while current_count[word] > word_count[word]:
                            left_word = s[left:left + word_len]
                            current_count[left_word] -= 1
                            if current_count[left_word] < word_count[left_word]:
                                count -= 1
                            left += word_len            # Shrink window from the left.
                else:
                    current_count.clear()               # Invalid word resets everything.
                    count = 0
                    left = right

                if count == num_words:
                    res.append(left)                    # Found valid window.

        return res

