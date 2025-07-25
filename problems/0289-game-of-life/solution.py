class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Problem: 0289 - Game of Life
        
        Update the board in-place to the next state according to Conway's
        Game of Life rules. Uses bit manipulation to store both current
        and next state in the same cell.
        
        Approach:
        - Use 2 bits: bit 0 for current state, bit 1 for next state
        - Count live neighbors for each cell
        - Apply rules to determine next state
        - Shift right to move next state to current state
        
        Time complexity: O(m * n) where m, n are board dimensions.
        Space complexity: O(1) as we modify in-place.
        """
        m, n = len(board), len(board[0])
        
        # First pass: calculate next state for each cell.
        for i in range(m):
            for j in range(n):
                # Count live neighbors.
                live_neighbors = self.count_live_neighbors(board, i, j, m, n)
                
                # Apply Game of Life rules.
                if board[i][j] == 1:  # Currently alive.
                    # Rule 2: Live cell with 2 or 3 neighbors survives.
                    if live_neighbors == 2 or live_neighbors == 3:
                        board[i][j] |= 2  # Set bit 1 to indicate alive in next state.
                else:  # Currently dead.
                    # Rule 4: Dead cell with exactly 3 neighbors becomes alive.
                    if live_neighbors == 3:
                        board[i][j] |= 2  # Set bit 1 to indicate alive in next state.
        
        # Second pass: update board to next state.
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1  # Shift right to move next state to current.
    
    def count_live_neighbors(self, board: List[List[int]], row: int, col: int, 
                           m: int, n: int) -> int:
        # Count live neighbors in all 8 directions.
        count = 0
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), 
                     (0, 1), (1, -1), (1, 0), (1, 1)]
        
        for dx, dy in directions:
            nx, ny = row + dx, col + dy
            # Check bounds and count if neighbor is currently alive.
            if 0 <= nx < m and 0 <= ny < n:
                count += board[nx][ny] & 1  # Check bit 0 for current state.
        
        return count
