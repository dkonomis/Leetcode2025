class Solution {
public:
    bool canWinNim(int n) {
        /**
         * Problem: 0292 - Nim Game
         * 
         * In the Nim game, two players take turns removing 1-3 stones from a heap.
         * The player who takes the last stone wins. We need to determine if the
         * first player can win with optimal play.
         * 
         * Approach: The key insight is that if there are 4 stones, the first player
         * always loses because no matter how many stones they take (1, 2, or 3), 
         * the opponent can always take the remaining stones. This pattern repeats 
         * for all multiples of 4.
         * 
         * Time complexity: O(1).
         * Space complexity: O(1).
         */
        
        // Check if n is not divisible by 4.
        return n % 4 != 0;
    }
};
