class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        """
        Problem: 0299 - Bulls and Cows
        
        Count bulls (exact matches) and cows (digits in wrong positions).
        
        Approach: Single pass with hash map. Track bulls immediately when
        positions match. For non-matches, use a counter array to track
        unmatched digits. When we see a digit in secret that was previously
        seen in guess (or vice versa), it's a cow.
        
        Time complexity: O(n), where n is the length of the strings.
        Space complexity: O(1), since we only track 10 digits (0-9).
        """
        bulls = 0
        cows = 0
        # Counter for unmatched digits (index represents digit 0-9).
        counter = [0] * 10
        
        for i in range(len(secret)):
            s = int(secret[i])
            g = int(guess[i])
            
            if s == g:
                # Exact match - it's a bull.
                bulls += 1
            else:
                # Check if current secret digit was seen in previous guesses.
                if counter[s] < 0:
                    cows += 1
                # Check if current guess digit was seen in previous secrets.
                if counter[g] > 0:
                    cows += 1
                
                # Update counters: +1 for secret, -1 for guess.
                counter[s] += 1
                counter[g] -= 1
        
        return f"{bulls}A{cows}B"
