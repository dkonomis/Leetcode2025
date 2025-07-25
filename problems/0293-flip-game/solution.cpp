class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        /**
         * Problem: 0293 - Flip Game
         * 
         * Given a string with only '+' and '-' characters, find all possible states
         * after flipping one occurrence of consecutive "++" to "--".
         * 
         * Approach: Iterate through the string and check each adjacent pair of characters.
         * If we find "++", create a new string with those positions flipped to "--".
         * We temporarily modify the string in-place and then restore it to avoid creating
         * multiple string copies.
         * 
         * Time complexity: O(n), where n is the length of the string.
         * Space complexity: O(1) excluding the output list.
         */
        
        vector<string> res;
        
        // Check each adjacent pair of characters.
        for (int i = 0; i < currentState.length() - 1; i++) {
            // If we find two consecutive '+' characters.
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                // Temporarily flip "++" to "--".
                currentState[i] = '-';
                currentState[i + 1] = '-';
                res.push_back(currentState);
                
                // Restore the original state.
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        
        return res;
    }
};
