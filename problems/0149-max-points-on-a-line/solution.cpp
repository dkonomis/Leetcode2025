class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        /**
         * Problem: 0149 - Max Points on a Line
         * 
         * Find the maximum number of points that lie on the same straight line.
         * 
         * Approach:
         * For each point as anchor, calculate slopes to all other points.
         * Points with same slope from anchor are on same line.
         * Use GCD to avoid floating point issues by storing slope as reduced fraction.
         * 
         * Time complexity: O(n^2).
         * Space complexity: O(n) for the slope hashmap.
         */
        
        if (points.size() <= 2) {
            return points.size();
        }
        
        int res = 0;
        
        // Try each point as the anchor.
        for (int i = 0; i < points.size(); i++) {
            map<pair<int, int>, int> slopes;  // slope -> count mapping.
            int max_count = 0;
            
            // Calculate slope from anchor to every other point.
            for (int j = i + 1; j < points.size(); j++) {
                // Calculate differences.
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                // Reduce fraction to avoid floating point issues.
                int g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;
                
                // Normalize sign - keep denominator positive.
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0 && dy < 0) {
                    // Handle vertical line case.
                    dy = -dy;
                }
                
                pair<int, int> slope = {dy, dx};
                
                // Count points with this slope.
                slopes[slope]++;
                max_count = max(max_count, slopes[slope]);
            }
            
            // Add 1 for the anchor point itself.
            res = max(res, max_count + 1);
        }
        
        return res;
    }
    
private:
    int gcd(int a, int b) {
        /**Calculate greatest common divisor.**/
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
