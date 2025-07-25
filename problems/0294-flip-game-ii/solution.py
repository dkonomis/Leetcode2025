class Solution:
    def canWin(self, currentState: str) -> bool:
        """
        Problem: 0294 - Flip Game II
        
        Determine if the starting player can guarantee a win in the Flip Game.
        Two players take turns flipping consecutive "++" to "--". The player
        who cannot make a move loses.
        
        Approach: Use backtracking with memoization. For each possible move,
        flip "++" to "--" and recursively check if the opponent loses. If any
        move forces the opponent to lose, the current player wins.
        
        Time complexity: O(n * 2^n), where n is the length of the string.
        Space complexity: O(2^n) for memoization cache.
        """
        memo = {}
        
        def canWinHelper(state):
            # Check if we've already computed this state.
            if state in memo:
                return memo[state]
            
            # Try all possible moves.
            for i in range(len(state) - 1):
                if state[i:i+2] == '++':
                    # Make a move by flipping "++" to "--".
                    next_state = state[:i] + '--' + state[i+2:]
                    
                    # If opponent cannot win from next state, current player wins.
                    if not canWinHelper(next_state):
                        memo[state] = True
                        return True
            
            # No winning move found.
            memo[state] = False
            return False
        
        return canWinHelper(currentState)
