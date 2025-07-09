# 0064. Minimum Path Sum

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/minimum-path-sum/

---

## Problem

Given an `m × n` grid filled with non-negative numbers, find a path from the top-left corner to the bottom-right corner which minimizes the sum of all numbers along the path.  
You can only move either **down** or **right** at any point in time.

**Example 1:**

    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]  
    Output: 7  
    **Explanation:** Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum to 7.

**Example 2:**

    Input: grid = [[1,2,3],[4,5,6]]  
    Output: 12  
    **Explanation:** The path 1 → 2 → 3 → 6 minimizes the sum to 12.

**Constraints:**

- `m == grid.length`  
- `n == grid[i].length`  
- `1 ≤ m, n ≤ 200`  
- `0 ≤ grid[i][j] ≤ 100`

