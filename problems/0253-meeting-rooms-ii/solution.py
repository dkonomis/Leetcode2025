class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        """
        Problem: 0253 - Meeting Rooms II
        
        Find minimum conference rooms needed by tracking room end times.
        Sort intervals by start time, then use a min heap to track the
        earliest ending meeting. If a new meeting starts after the earliest
        ending, reuse that room; otherwise, allocate a new room.
        
        Time complexity: O(n log n) where n is the number of intervals.
        Space complexity: O(n) for the heap.
        """
        if not intervals:
            return 0
        
        # Sort intervals by start time.
        intervals.sort()
        
        # Min heap to track end times of meetings in each room.
        rooms = []
        
        # Add first meeting's end time.
        heapq.heappush(rooms, intervals[0][1])
        
        # Process remaining meetings.
        for i in range(1, len(intervals)):
            # If current meeting starts after earliest ending, reuse that room.
            if intervals[i][0] >= rooms[0]:
                heapq.heappop(rooms)
            
            # Add current meeting's end time to heap.
            heapq.heappush(rooms, intervals[i][1])
        
        # Heap size represents number of rooms needed.
        return len(rooms)
