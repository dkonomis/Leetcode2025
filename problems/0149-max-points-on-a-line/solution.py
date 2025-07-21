class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        """
        Problem: 0149 - Max Points on a Line
        
        Find the maximum number of points that lie on the same straight line.
        
        Approach:
        For each point as anchor, calculate slopes to all other points.
        Points with same slope from anchor are on same line.
        Use GCD to avoid floating point issues by storing slope as reduced fraction.
        
        Time complexity: O(n^2).
        Space complexity: O(n) for the slope hashmap.
        """
        if len(points) <= 2:
            return len(points)
        
        def gcd(a, b):
            """Calculate greatest common divisor."""
            while b:
                a, b = b, a % b
            return a
        
        res = 0
        
        # Try each point as the anchor.
        for i in range(len(points)):
            slopes = {}  # slope -> count mapping.
            max_count = 0
            
            # Calculate slope from anchor to every other point.
            for j in range(i + 1, len(points)):
                # Calculate differences.
                dx = points[j][0] - points[i][0]
                dy = points[j][1] - points[i][1]
                
                # Handle vertical line (dx = 0).
                if dx == 0:
                    slope = ('inf', 0)
                # Handle horizontal line (dy = 0).
                elif dy == 0:
                    slope = (0, 'inf')
                else:
                    # Reduce fraction to avoid floating point issues.
                    g = gcd(abs(dx), abs(dy))
                    dx, dy = dx // g, dy // g
                    
                    # Normalize sign - keep denominator positive.
                    if dx < 0:
                        dx, dy = -dx, -dy
                    
                    slope = (dy, dx)
                
                # Count points with this slope.
                slopes[slope] = slopes.get(slope, 0) + 1
                max_count = max(max_count, slopes[slope])
            
            # Add 1 for the anchor point itself.
            res = max(res, max_count + 1)
        
        return res
