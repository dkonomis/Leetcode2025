class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        """
        Problem: 0293 - Flip Game
        
        Given a string with only '+' and '-' characters, find all possible states
        after flipping one occurrence of consecutive "++" to "--".
        
        Approach: Iterate through the string and check each adjacent pair of characters.
        If we find "++", create a new string with those positions flipped to "--".
        
        Time complexity: O(n), where n is the length of the string.
        Space complexity: O(1) excluding the output list.
        """
        res = []
        
        # Check each adjacent pair of characters.
        for i in range(len(currentState) - 1):
            # If we find two consecutive '+' characters.
            if currentState[i] == '+' and currentState[i + 1] == '+':
                # Create new state by flipping "++" to "--".
                new_state = currentState[:i] + '--' + currentState[i + 2:]
                res.append(new_state)
        
        return res
