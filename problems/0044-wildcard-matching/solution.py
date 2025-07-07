# 0044. Wildcard Matching

**Difficulty:** Hard  
**Link:** [https://leetcode.com/problems/wildcard-matching](https://leetcode.com/problems/wildcard-matching)

---

### Problem

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

- `'?'` matches any single character.
- `'*'` matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

---

### Example 1

**Input:**  
    s = "aa", p = "a"  
**Output:**  
    false  
**Explanation:**  
    `'a'` does not match the entire string `"aa"`.

---

### Example 2

**Input:**  
    s = "aa", p = "*"  
**Output:**  
    true  
**Explanation:**  
    `'*'` matches any sequence.

---

### Example 3

**Input:**  
    s = "cb", p = "?a"  
**Output:**  
    false  
**Explanation:**  
    `'?'` matches `'c'`, but `'a'` does not match `'b'`.

---

### Constraints

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'?'`, or `'*'`.

