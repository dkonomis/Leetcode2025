# 0205. Isomorphic Strings

**Difficulty**: Easy  
**Link**: LeetCode 205

---

Given two strings `s` and `t`, determine if they are isomorphic.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

**Input:** `s = "egg", t = "add"`  
**Output:** `true`  
**Explanation:** The strings s and t can be made identical by:
* Mapping `'e'` to `'a'`.
* Mapping `'g'` to `'d'`.

**Example 2:**

**Input:** `s = "foo", t = "bar"`  
**Output:** `false`  
**Explanation:** The characters `'o'` and `'o'` map to `'a'` and `'r'` respectively. Since `'o'` cannot map to two different characters, they are not isomorphic.

**Example 3:**

**Input:** `s = "paper", t = "title"`  
**Output:** `true`

**Constraints:**

* `1 <= s.length <= 5 * 10⁴`
* `t.length == s.length`
* `s` and `t` consist of any valid ASCII character.
