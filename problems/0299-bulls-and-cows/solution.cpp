class Solution {
public:
    string getHint(string secret, string guess) {
        /**
         * Problem: 0299 - Bulls and Cows
         * 
         * Count bulls (exact matches) and cows (digits in wrong positions).
         * 
         * Approach: Single pass with counter array. Track bulls immediately when
         * positions match. For non-matches, use a counter array to track
         * unmatched digits. Positive count means digit seen in secret waiting
         * for match in guess. Negative count means digit seen in guess waiting
         * for match in secret. When they meet, it's a cow!
         * 
         * Time complexity: O(n), where n is the length of the strings.
         * Space complexity: O(1), since we only track 10 digits (0-9).
         */
        
        int bulls = 0;
        int cows = 0;
        // Counter for unmatched digits (index represents digit 0-9).
        int counter[10] = {0};
        
        for (int i = 0; i < secret.length(); i++) {
            int s = secret[i] - '0';  // Convert char to int.
            int g = guess[i] - '0';   // Convert char to int.
            
            if (s == g) {
                // Exact match - it's a bull.
                bulls++;
            } else {
                // Check if current secret digit was seen in previous guesses.
                if (counter[s] < 0) {
                    cows++;
                }
                // Check if current guess digit was seen in previous secrets.
                if (counter[g] > 0) {
                    cows++;
                }
                
                // Update counters: +1 for secret, -1 for guess.
                counter[s]++;
                counter[g]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
