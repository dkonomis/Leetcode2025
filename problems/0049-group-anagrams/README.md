# 0049. Group Anagrams

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/group-anagrams/

---

## Problem

Given an array of strings `strs`, **group the anagrams together**. You can return the answer **in any order**. An **anagram** is a string formed by rearranging the letters of another string, using all the original characters exactly once.

**Example 1:**

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["eat","tea","ate"],["tan","nat"],["bat"]]

**Example 2:**

    Input: strs = [""]
    Output: [[""]]

**Example 3:**

    Input: strs = ["a"]
    Output: [["a"]]

**Constraints:**

- `1 ≤ strs.length ≤ 10⁴`  
- `0 ≤ strs[i].length ≤ 100`  
- `strs[i]` consists of lowercase English letters.

---

### Explanation

Group all strings that are anagrams of each other into separate lists. The order of the groups and the order of strings within each group do not matter. :contentReference[oaicite:0]{index=0}

