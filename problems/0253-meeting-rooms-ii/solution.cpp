class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        /**
         * Problem: 0253 - Meeting Rooms II
         * 
         * Find minimum conference rooms needed by tracking room end times.
         * Sort intervals by start time, then use a min heap to track the
         * earliest ending meeting. If a new meeting starts after the earliest
         * ending, reuse that room; otherwise, allocate a new room.
         * 
         * Time complexity: O(n log n) where n is the number of intervals.
         * Space complexity: O(n) for the heap.
         */
        
        if (intervals.empty()) {
            return 0;
        }
        
        // Sort intervals by start time.
        sort(intervals.begin(), intervals.end());
        
        // Min heap to track end times of meetings in each room.
        priority_queue<int, vector<int>, greater<int>> rooms;
        
        // Add first meeting's end time.
        rooms.push(intervals[0][1]);
        
        // Process remaining meetings.
        for (int i = 1; i < intervals.size(); i++) {
            // If current meeting starts after earliest ending, reuse that room.
            if (intervals[i][0] >= rooms.top()) {
                rooms.pop();
            }
            
            // Add current meeting's end time to heap.
            rooms.push(intervals[i][1]);
        }
        
        // Heap size represents number of rooms needed.
        return rooms.size();
    }
};
