class Solution {
public:
    bool canWin(string currentState) {
        /**
         * Problem: 0294 - Flip Game II
         * 
         * Determine if the starting player can guarantee a win in the Flip Game.
         * Two players take turns flipping consecutive "++" to "--". The player
         * who cannot make a move loses.
         * 
         * Approach: Use backtracking with memoization. For each possible move,
         * flip "++" to "--" and recursively check if the opponent loses. If any
         * move forces the opponent to lose, the current player wins. We use an
         * unordered_map to cache results for previously seen states.
         * 
         * Time complexity: O(n * 2^n), where n is the length of the string.
         * Space complexity: O(2^n) for memoization cache.
         */
        
        unordered_map<string, bool> memo;
        return canWinHelper(currentState, memo);
    }
    
private:
    bool canWinHelper(string state, unordered_map<string, bool>& memo) {
        // Check if we've already computed this state.
        if (memo.find(state) != memo.end()) {
            return memo[state];
        }
        
        // Try all possible moves.
        for (int i = 0; i < state.length() - 1; i++) {
            if (state[i] == '+' && state[i + 1] == '+') {
                // Make a move by flipping "++" to "--".
                state[i] = '-';
                state[i + 1] = '-';
                
                // If opponent cannot win from next state, current player wins.
                if (!canWinHelper(state, memo)) {
                    // Restore the state before caching and returning.
                    state[i] = '+';
                    state[i + 1] = '+';
                    memo[state] = true;
                    return true;
                }
                
                // Restore the state for next iteration.
                state[i] = '+';
                state[i + 1] = '+';
            }
        }
        
        // No winning move found.
        memo[state] = false;
        return false;
    }
};
