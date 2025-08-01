# 0056. Merge Intervals

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/merge-intervals/

---

## Problem

Given an array of intervals `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

**Example 1:**

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]  
    Output: [[1,6],[8,10],[15,18]]  
    **Explanation:** Intervals [1,3] and [2,6] overlap and are merged into [1,6].

**Example 2:**

    Input: intervals = [[1,4],[4,5]]  
    Output: [[1,5]]  
    **Explanation:** Intervals [1,4] and [4,5] overlap and are merged into [1,5].

**Constraints:**

- `1 ≤ intervals.length ≤ 10⁴`  
- `intervals[i].length == 2`  
- `0 ≤ start_i ≤ end_i ≤ 10⁵`

