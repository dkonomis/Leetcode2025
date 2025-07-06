# 0030. Substring with Concatenation of All Words

**Difficulty:** Hard  
**Link:** [https://leetcode.com/problems/substring-with-concatenation-of-all-words](https://leetcode.com/problems/substring-with-concatenation-of-all-words)

---

### Problem

You are given a string `s` and an array of strings `words`. All the strings of `words` are of the same length.

A **concatenated substring** in `s` is a substring that contains all the strings of any permutation of `words` concatenated.

For example, if `words = ["ab","cd","ef"]`, then `"abcdef"`, `"abefcd"`, `"cdabef"`, etc. are all concatenated substrings.

Return the starting indices of all the concatenated substrings in `s`. You can return the answer in **any order**.

---

### Example 1

**Input:**  
s = "barfoothefoobarman", words = ["foo","bar"]

**Output:**  
[0,9]

**Explanation:**  
Substrings starting at index 0 and 9 are `"barfoo"` and `"foobar"`.

---

### Example 2

**Input:**  
s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

**Output:**  
[]

---

### Example 3

**Input:**  
s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

**Output:**  
[6,9,12]

---

### Constraints

- `1 <= s.length <= 10⁴`  
- `1 <= words.length <= 5000`  
- `1 <= words[i].length <= 30`  
- `s` and `words[i]` consist of lowercase English letters.

