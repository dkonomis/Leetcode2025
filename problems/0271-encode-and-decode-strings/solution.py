class Codec:
    def encode(self, strs: List[str]) -> str:
        """
        Problem: 0271 - Encode and Decode Strings
        
        Encode a list of strings into a single string that can be decoded back.
        
        Approach: Use length-prefix encoding. For each string, encode as "length#string".
        This handles any ASCII characters including special ones. The # delimiter after
        the length ensures we can parse the length correctly.
        
        Time complexity: O(n) where n is total number of characters in all strings.
        Space complexity: O(n) for the encoded string.
        """
        encoded = []
        for s in strs:
            # Encode each string as "length#string".
            encoded.append(str(len(s)) + '#' + s)
        return ''.join(encoded)
        
    def decode(self, s: str) -> List[str]:
        """
        Decode the encoded string back to list of strings.
        
        Approach: Parse length prefix, then extract exact number of characters.
        This avoids delimiter collision issues since we know exact string length.
        
        Time complexity: O(n) where n is length of encoded string.
        Space complexity: O(n) for the decoded list.
        """
        res = []
        i = 0
        
        while i < len(s):
            # Find the delimiter '#' to get length.
            j = i
            while s[j] != '#':
                j += 1
            
            # Parse the length.
            length = int(s[i:j])
            
            # Extract the string of given length.
            start = j + 1
            end = start + length
            res.append(s[start:end])
            
            # Move to next encoded string.
            i = end
        
        return res


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
