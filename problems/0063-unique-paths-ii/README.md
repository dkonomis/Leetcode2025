# 0063. Unique Paths II

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/unique-paths-ii/

---

## Problem

A robot is located at the top-left corner of an `m × n` grid with obstacles. The grid is represented by a 2D array `obstacleGrid`, where `obstacleGrid[i][j] == 1` indicates an obstacle and `0` indicates a free space.

Return the number of unique paths for the robot to reach the bottom-right corner. The robot can only move right or down at each step, and cannot move onto obstacles.

**Example 1:**

    Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]  
    Output: 2  
    **Explanation:** There are two paths around the obstacle.

**Example 2:**

    Input: obstacleGrid = [[0,1],[0,0]]  
    Output: 1

**Constraints:**

- `m == obstacleGrid.length`  
- `n == obstacleGrid[i].length`  
- `1 ≤ m, n ≤ 100`  
- `obstacleGrid[i][j]` is `0` or `1`.  
- `grid[0][0] == grid[m-1][n-1] == 0`

---

