# 0130. Surrounded Regions

**Difficulty**: Medium  
**Link**: [LeetCode 130](https://leetcode.com/problems/surrounded-regions/)

---

Given an `m x n` matrix `board` containing `'X'` and `'O'`, capture all regions that are 4-directionally surrounded by `'X'`.

A region is **captured** by flipping all `'O'`s into `'X'`s in that surrounded region.

**Example 1:**

    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    Explanation: Notice that an 'O' in the corner or on the border is not surrounded because it is on the edge of the board.

**Example 2:**

    Input: board = [["X"]]
    Output: [["X"]]

**Constraints:**

* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 200`
* `board[i][j]` is `'X'` or `'O'`.

**Note:** This question is the same as 1020: https://leetcode.com/problems/number-of-enclaves/
