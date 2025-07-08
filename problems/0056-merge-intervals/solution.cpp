#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        56. Merge Intervals

        Summary:
        Given a list of intervals, merge all overlapping intervals and return the result.

        Approach:
        - Sort the intervals based on their start times.
        - Initialize an empty result vector.
        - For each interval:
            - If it doesn't overlap with the last one in res, add it.
            - If it overlaps, merge by extending the end of the last interval.

        Time complexity: O(n log n), due to sorting.
        Space complexity: O(n), for the result vector.
        */
        if (intervals.empty()) return {};

        // Sort intervals by start time.
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;  // stores merged intervals.

        // Iterate through each interval and merge it if it overlaps with the last in res.
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);  // no overlap, add new interval.
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);  // merge overlap.
            }
        }

        return res;
    }
};

