# 0048. Rotate Image

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/rotate-image/

---

## Problem

You are given an `n × n` 2D matrix representing an image. Rotate the image **by 90 degrees clockwise**, performing the rotation **in‑place**, meaning you must modify the input matrix directly and **do not allocate another 2D matrix**.

**Example 1:**

    Input: matrix = [[1,2,3],
                    [4,5,6],
                    [7,8,9]]
    Output: [[7,4,1],
             [8,5,2],
             [9,6,3]]

**Example 2:**

    Input: matrix = [[5, 1, 9,11],
                    [2, 4, 8,10],
                    [13,3, 6, 7],
                    [15,14,12,16]]
    Output: [[15,13, 2, 5],
             [14, 3, 4, 1],
             [12, 6, 8, 9],
             [16, 7,10,11]]

**Constraints:**

- `n == matrix.length == matrix[i].length`
- `1 ≤ n ≤ 20`
- `-1000 ≤ matrix[i][j] ≤ 1000`

