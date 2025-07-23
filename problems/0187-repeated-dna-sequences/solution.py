class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        """
        Problem: 0187 - Repeated DNA Sequences
        
        Find all 10-letter-long DNA sequences that occur more than once.
        DNA consists of nucleotides: A, C, G, T.
        
        Approach:
        - Use a sliding window of size 10 to check all substrings
        - Use a hash map to count occurrences of each sequence
        - Add to result when count becomes exactly 2 (avoid duplicates)
        
        Time complexity: O(n) where n is the length of the string.
        Space complexity: O(n) for storing sequences in the hash map.
        """
        if len(s) < 10:
            return []
        
        # Dictionary to count occurrences of each 10-letter sequence.
        sequence_count = {}
        res = []
        
        # Slide through the string with a window of size 10.
        for i in range(len(s) - 9):
            # Extract the current 10-letter sequence.
            sequence = s[i:i + 10]
            
            # Update count in dictionary.
            sequence_count[sequence] = sequence_count.get(sequence, 0) + 1
            
            # Add to result when we see it exactly twice.
            # This ensures we don't add duplicates to the result.
            if sequence_count[sequence] == 2:
                res.append(sequence)
        
        return res
