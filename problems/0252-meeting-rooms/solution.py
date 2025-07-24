class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        """
        Problem: 0252 - Meeting Rooms
        
        Determine if a person can attend all meetings by checking for overlaps.
        Sort intervals by start time, then check if any meeting starts before
        the previous one ends.
        
        Time complexity: O(n log n) where n is the number of intervals.
        Space complexity: O(1) excluding the sort space.
        """
        # Sort intervals by start time.
        intervals.sort()
        
        # Check each adjacent pair for overlap.
        for i in range(1, len(intervals)):
            # If current meeting starts before previous ends, there's overlap.
            if intervals[i][0] < intervals[i - 1][1]:
                return False
        
        return True
