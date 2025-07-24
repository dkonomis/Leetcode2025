class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        """
        Problem: 0267 - Palindrome Permutation II
        
        Generate all palindromic permutations of a string.
        
        Approach: Count character frequencies. Check if palindrome is possible (at most one
        odd count). Use backtracking to build palindromes by placing characters symmetrically
        around the center. Only need to generate the first half since the second half mirrors it.
        
        Time complexity: O((n/2)!) where n is the length of the string.
        Space complexity: O(n) for recursion stack and character count.
        """
        # Count character frequencies.
        count = {}
        for c in s:
            count[c] = count.get(c, 0) + 1
        
        # Find middle character for odd-length palindromes.
        mid = ""
        odd_count = 0
        for c, freq in count.items():
            if freq % 2 == 1:
                odd_count += 1
                mid = c
        
        # More than one odd frequency means no palindrome possible.
        if odd_count > 1:
            return []
        
        # Prepare characters for backtracking (half frequencies).
        chars = []
        for c, freq in count.items():
            chars.extend([c] * (freq // 2))
        
        # Generate all permutations of half string.
        res = []
        used = [False] * len(chars)
        
        def backtrack(path):
            # Complete palindrome found.
            if len(path) == len(chars):
                # Build full palindrome: first_half + mid + reversed_first_half.
                palindrome = ''.join(path) + mid + ''.join(path[::-1])
                res.append(palindrome)
                return
            
            # Try each unused character.
            for i in range(len(chars)):
                # Skip if used or duplicate of previous.
                if used[i] or (i > 0 and chars[i] == chars[i-1] and not used[i-1]):
                    continue
                
                # Use this character.
                used[i] = True
                # Recursively build the rest of the palindrome with this choice.
                backtrack(path + [chars[i]])
                # Backtrack: undo the choice to try other possibilities.
                used[i] = False
        
        backtrack([])
        return res
