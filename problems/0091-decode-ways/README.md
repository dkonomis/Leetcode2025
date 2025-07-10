# 0091. Decode Ways

**Difficulty**: Medium  
**Link**: [LeetCode 91](https://leetcode.com/problems/decode-ways/)

---

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:  
"1" -> 'A'  
"2" -> 'B'  
...  
"26" -> 'Z'  

Given a string `s` containing only digits, return *the number of ways to decode it*.  
The test cases are generated so that the answer fits in a 32‑bit integer.

**Example 1:**  
    **Input:** s = "12"  
    **Output:** 2  
    **Explanation:** "12" could be decoded as "AB" (1 2) or "L" (12).

**Example 2:**  
    **Input:** s = "226"  
    **Output:** 3  
    **Explanation:** "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

**Example 3:**  
    **Input:** s = "0"  
    **Output:** 0  
    **Explanation:** There is no valid decode for "0".

**Example 4:**  
    **Input:** s = "1"  
    **Output:** 1  

**Example 5:**  
    **Input:** s = "10"  
    **Output:** 1  
    **Explanation:** "10" decodes to "J".

**Constraints:**  
- 1 <= s.length <= 100  
- `s` contains only digits and may contain leading zero(s).

