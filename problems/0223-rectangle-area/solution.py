class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        """
        Problem: 0223 - Rectangle Area
        
        Calculate total area covered by two rectangles.
        Total area = area of rectangle A + area of rectangle B - overlapping area.
        To find overlap, calculate intersection rectangle dimensions.
        
        Time complexity: O(1).
        Space complexity: O(1).
        """
        # Calculate area of rectangle A.
        area_a = (ax2 - ax1) * (ay2 - ay1)
        
        # Calculate area of rectangle B.
        area_b = (bx2 - bx1) * (by2 - by1)
        
        # Calculate intersection rectangle coordinates.
        # Left edge of intersection is rightmost of the two left edges.
        intersection_x1 = max(ax1, bx1)
        # Right edge of intersection is leftmost of the two right edges.
        intersection_x2 = min(ax2, bx2)
        # Bottom edge of intersection is topmost of the two bottom edges.
        intersection_y1 = max(ay1, by1)
        # Top edge of intersection is bottommost of the two top edges.
        intersection_y2 = min(ay2, by2)
        
        # Calculate intersection area.
        # If there's no overlap, width or height will be negative.
        intersection_width = max(0, intersection_x2 - intersection_x1)
        intersection_height = max(0, intersection_y2 - intersection_y1)
        intersection_area = intersection_width * intersection_height
        
        # Total area is sum of both rectangles minus the overlap.
        res = area_a + area_b - intersection_area
        
        return res
