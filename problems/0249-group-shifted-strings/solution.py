class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        """
        Problem: 0249 - Group Shifted Strings
        
        Group strings that belong to same shifting sequence.
        Use hash map with normalized keys representing shift pattern.
        Normalize by shifting first character to 'a'.
        
        Time complexity: O(n * m) where n is number of strings, m is average length.
        Space complexity: O(n * m) for the hash map.
        """
        groups = {}
        
        for s in strings:
            # Calculate the key by normalizing the string.
            # Shift pattern is represented by differences from first character.
            key = self.get_key(s)
            
            # Add string to its group.
            if key not in groups:
                groups[key] = []
            groups[key].append(s)
        
        # Return all groups as list of lists.
        return list(groups.values())
    
    def get_key(self, s: str) -> str:
        """Get normalized key representing the shift pattern."""
        if not s:
            return ""
        
        # Normalize by shifting first character to 'a'.
        # This creates a canonical form for each shift pattern.
        shift = ord(s[0]) - ord('a')
        key = []
        
        for char in s:
            # Shift character and handle wraparound.
            normalized = (ord(char) - ord('a') - shift) % 26
            key.append(chr(normalized + ord('a')))
        
        # Return string key.
        return ''.join(key)
