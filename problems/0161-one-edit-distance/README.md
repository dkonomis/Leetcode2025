# 0161. One Edit Distance

**Difficulty**: Medium

**Link**: LeetCode 161

---

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

- Insert exactly one character into s to get t.
- Delete exactly one character from s to get t.
- Replace exactly one character of s with a different character to get t.

**Example 1:**

    **Input**: s = "ab", t = "acb"
    **Output**: true
    **Explanation**: We can insert 'c' into s to get t.

**Example 2:**

    **Input**: s = "", t = ""
    **Output**: false
    **Explanation**: We cannot get t from s by only one step.

**Example 3:**

    **Input**: s = "1203", t = "1213"
    **Output**: true
    **Explanation**: We can replace '0' with '1' to get t.

**Constraints:**

- `0 <= s.length, t.length <= 10⁴`
- `s` and `t` consist of lowercase letters, uppercase letters, and digits.
