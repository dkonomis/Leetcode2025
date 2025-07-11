# 0097. Interleaving String

**Difficulty**: Hard  
**Link**: [LeetCode 97](https://leetcode.com/problems/interleaving-string/)

---

Given three strings `s1`, `s2`, and `s3`, return *`true` if `s3` is formed by an **interleaving** of `s1` and `s2`.*

An interleaving of two strings `s1` and `s2` is a configuration where they are divided into non-empty substrings:

    s1 = s1_1 + s1_2 + ... + s1_n  
    s2 = s2_1 + s2_2 + ... + s2_m

and

    s3 = s1_1 + s2_1 + s1_2 + s2_2 + ... + s1_n + s2_m

*Note*: `n` or `m` can be zero, meaning one string can be empty.

Given that, determine whether `s3` is an interleaving of `s1` and `s2`.

**Example 1:**  
    **Input:** s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"  
    **Output:** true

**Example 2:**  
    **Input:** s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"  
    **Output:** false

**Example 3:**  
    **Input:** s1 = "", s2 = "", s3 = ""  
    **Output:** true

**Constraints:**  
- `0 <= s1.length, s2.length <= 100`  
- `0 <= s3.length <= 200`

