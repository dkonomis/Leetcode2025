class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Problem: 0130 - Surrounded Regions
        
        Capture all regions surrounded by 'X' by flipping 'O' to 'X'.
        
        Approach:
        1. Find all 'O's connected to borders (these cannot be captured).
        2. Use BFS from all border 'O's to mark connected regions as safe.
        3. Flip all remaining 'O's to 'X' (these are truly surrounded).
        4. Restore safe regions back to 'O'.
        
        Time complexity: O(m * n) where m and n are board dimensions.
        Space complexity: O(m * n) for the queue in worst case.
        """
        if not board or not board[0]:
            return
        
        m, n = len(board), len(board[0])
        queue = []
        
        # Find all border 'O's and add them to queue.
        for i in range(m):
            for j in range(n):
                # Check if cell is on border and contains 'O'.
                if (i == 0 or i == m - 1 or j == 0 or j == n - 1) and board[i][j] == 'O':
                    queue.append((i, j))
                    board[i][j] = 'T'  # Mark as temporarily safe.
        
        # BFS to mark all 'O's connected to border as safe.
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while queue:
            row, col = queue.pop(0)
            
            # Check all 4 directions.
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                
                # Check bounds and if neighbor is 'O'.
                if (0 <= new_row < m and 0 <= new_col < n and 
                    board[new_row][new_col] == 'O'):
                    board[new_row][new_col] = 'T'  # Mark as safe.
                    queue.append((new_row, new_col))
        
        # Final pass: flip 'O' to 'X' (surrounded) and 'T' back to 'O' (safe).
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'  # Surrounded region.
                elif board[i][j] == 'T':
                    board[i][j] = 'O'  # Border-connected region.
