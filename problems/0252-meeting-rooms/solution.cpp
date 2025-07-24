class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        /**
         * Problem: 0252 - Meeting Rooms
         * 
         * Determine if a person can attend all meetings by checking for overlaps.
         * Sort intervals by start time, then check if any meeting starts before
         * the previous one ends.
         * 
         * Time complexity: O(n log n) where n is the number of intervals.
         * Space complexity: O(1) excluding the sort space.
         */
        
        // Sort intervals by start time.
        sort(intervals.begin(), intervals.end());
        
        // Check each adjacent pair for overlap.
        for (int i = 1; i < intervals.size(); i++) {
            // If current meeting starts before previous ends, there's overlap.
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        
        return true;
    }
};
