# 0076. Minimum Window Substring

**Difficulty**: Hard  
**Link**: [LeetCode 76](https://leetcode.com/problems/minimum-window-substring/)

---

## Problem

Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window*. If there is no such substring, return the empty string `""`.

The testcases will be generated such that the answer is unique.

---

### Example 1

**Input:**  
`s = "ADOBECODEBANC", t = "ABC"`  
**Output:**  
`"BANC"`

---

### Example 2

**Input:**  
`s = "a", t = "a"`  
**Output:**  
`"a"`

---

### Example 3

**Input:**  
`s = "a", t = "aa"`  
**Output:**  
`""`

---

### Constraints

- `m == s.length`  
- `n == t.length`  
- `1 <= m, n <= 10⁵`  
- `s` and `t` consist of uppercase and lowercase English letters.

---

### Follow-up

Could you find an algorithm that runs in O(m + n) time?

