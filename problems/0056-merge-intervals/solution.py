class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        """
        56. Merge Intervals

        Summary:
        Given a list of intervals, merge all overlapping intervals and return the result.

        Approach:
        - Sort the intervals based on their start times.
        - Initialize an empty result list and iterate over sorted intervals.
        - For each interval:
            - If it overlaps with the last interval in res, merge them.
            - Otherwise, append it as a new non-overlapping interval.

        Time complexity: O(n log n), for sorting the intervals.
        Space complexity: O(n), for the result list.
        """
        intervals.sort(key=lambda x: x[0])  # sort by start time.
        res = []  # merged intervals.

        # Iterate through each interval and merge if overlapping with the last one in res.
        for interval in intervals:
            if not res or res[-1][1] < interval[0]:
                res.append(interval)  # no overlap, add new interval.
            else:
                res[-1][1] = max(res[-1][1], interval[1])  # merge overlap.

        return res

