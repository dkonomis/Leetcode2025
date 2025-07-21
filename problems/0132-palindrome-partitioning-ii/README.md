# 0132. Palindrome Partitioning II

**Difficulty**: Hard  
**Link**: [LeetCode 132](https://leetcode.com/problems/palindrome-partitioning-ii/)

---

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**.

Return the **minimum cuts** needed for a palindrome partitioning of `s`.

**Example 1:**

    Input: s = "aab"
    Output: 1
    Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

**Example 2:**

    Input: s = "raceacar"
    Output: 0
    Explanation: "raceacar" is already a palindrome itself.

**Example 3:**

    Input: s = "abcde"
    Output: 4
    Explanation: The minimum palindrome partitioning is ["a","b","c","d","e"], which needs 4 cuts.

**Constraints:**

* `1 <= s.length <= 2000`
* `s` consists of lowercase English letters only.
