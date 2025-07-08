#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        57. Insert Interval

        Summary:
        Insert a new interval into a sorted, non-overlapping list of intervals.
        Merge any overlapping intervals as needed to maintain a valid result.

        Approach:
        - Traverse the intervals in three phases:
            1. Add all intervals that end before newInterval starts.
            2. Merge all intervals that overlap with newInterval by adjusting its bounds.
            3. Add the merged newInterval.
            4. Add the remaining intervals after newInterval ends.

        Time complexity: O(n), where n = intervals.size()
        Space complexity: O(n), for the result list.
        */
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // Add all intervals that end before newInterval starts.
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }

        // Merge all intervals that overlap with newInterval.
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);  // expand start
            newInterval[1] = max(newInterval[1], intervals[i][1]);  // expand end
            ++i;
        }

        // Add the merged newInterval.
        res.push_back(newInterval);

        // Add the remaining intervals.
        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};

