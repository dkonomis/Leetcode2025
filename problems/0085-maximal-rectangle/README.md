# 0085. Maximal Rectangle

**Difficulty**: Hard  
**Link**: [LeetCode 85](https://leetcode.com/problems/maximal-rectangle/)

---

## Problem

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, return *the area of the largest rectangle containing only `1`'s*.

---

### Example 1

**Input:**  
`matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]`  
**Output:**  
`6`  
**Explanation:**  
The maximal rectangle is formed by the 3rd row, columns 1 through 4.

---

### Example 2

**Input:**  
`matrix = [["0"]]`  
**Output:**  
`0`

---

### Example 3

**Input:**  
`matrix = [["1"]]`  
**Output:**  
`1`

---

### Constraints

- `rows == matrix.length`
- `cols == matrix[i].length`
- `1 <= row, cols <= 200`
- `matrix[i][j]` is `'0'` or `'1'`.

