# 0057. Insert Interval

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/insert-interval/

---

## Problem

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [start_i, end_i]` **sorted by** `start_i`, and a new interval `newInterval = [start, end]`.

Insert `newInterval` into `intervals` so that the resulting list of intervals is still sorted by start time **and** merged as necessary (i.e., no two intervals overlap).  
Return the updated list of intervals.

**Example 1:**

    Input: intervals = [[1,3],[6,9]],
           newInterval = [2,5]
    Output: [[1,5],[6,9]]

**Example 2:**

    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]],
           newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: The new interval [4,8] overlaps [3,5], [6,7] and [8,10]; these are merged into [3,10].

**Example 3:**

    Input: intervals = [],
           newInterval = [5,7]
    Output: [[5,7]]

**Constraints:**

- `0 ≤ intervals.length ≤ 10⁴`  
- `intervals[i].length == 2`  
- `0 ≤ start_i ≤ end_i ≤ 10⁵`  
- `newInterval.length == 2`  
- `0 ≤ start ≤ end ≤ 10⁵`

