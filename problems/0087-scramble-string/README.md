# 0087. Scramble String

**Difficulty**: Hard  
**Link**: [LeetCode 87](https://leetcode.com/problems/scramble-string/)

---

## Problem

We can scramble a string s to get a string t using the following algorithm:

1. If the length of the string is 1, stop.
2. If the length is > 1, split the string into two non-empty substrings at a random index.
3. Recursively scramble each substring.
4. Swap the two children with a 50% probability.

Given two strings `s1` and `s2` of the same length, return `true` if `s2` is a scrambled string of `s1`.

---

### Example 1

**Input:**  
`s1 = "great", s2 = "rgeat"`  
**Output:**  
`true`

---

### Example 2

**Input:**  
`s1 = "abcde", s2 = "caebd"`  
**Output:**  
`false`

---

### Example 3

**Input:**  
`s1 = "a", s2 = "a"`  
**Output:**  
`true`

---

### Constraints

- `s1.length == s2.length`
- `1 <= s1.length <= 30`
- `s1` and `s2` consist of lowercase English letters.

