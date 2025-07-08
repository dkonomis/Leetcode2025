class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        """
        57. Insert Interval

        Summary:
        Insert a new interval into a list of non-overlapping, sorted intervals.
        Merge any overlapping intervals as needed to maintain a valid result.

        Approach:
        - Iterate through intervals in order.
        - Add all intervals that end before the new interval starts.
        - Merge all intervals that overlap with the new interval.
        - Add the merged interval.
        - Add all remaining intervals after the new interval ends.

        Time complexity: O(n), where n = len(intervals)
        Space complexity: O(n), for the result list
        """
        res = []
        i, n = 0, len(intervals)

        # Add all intervals that come before newInterval.
        while i < n and intervals[i][1] < newInterval[0]:
            res.append(intervals[i])
            i += 1

        # Merge all intervals that overlap with newInterval.
        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])  # expand start
            newInterval[1] = max(newInterval[1], intervals[i][1])  # expand end
            i += 1

        # Add the merged newInterval.
        res.append(newInterval)

        # Add remaining intervals after newInterval.
        while i < n:
            res.append(intervals[i])
            i += 1

        return res

