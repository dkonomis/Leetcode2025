# 0038. Count and Say

**Difficulty:** Medium  
**Link:** [https://leetcode.com/problems/count-and-say](https://leetcode.com/problems/count-and-say)

---

### Problem

The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:

- `countAndSay(1) = "1"`
- `countAndSay(n)` is the way you would "say" the previous term.

You start with `"1"` and count and say the digits to generate each subsequent term.

To determine the next term, read the current term digit by digit, grouping same digits together and saying the count followed by the digit.

For example:
- `1` is read as `"one 1"` → `"11"`
- `11` is read as `"two 1s"` → `"21"`
- `21` is read as `"one 2, one 1"` → `"1211"`
- and so on.

**Given a positive integer `n`, return the `n`th term of the count-and-say sequence.**

---

### Example 1

**Input:**  
n = 1

**Output:**  
"1"

**Explanation:**  
This is the base case.

---

### Example 2

**Input:**  
n = 4

**Output:**  
"1211"

**Explanation:**  
countAndSay(1) = "1"  
countAndSay(2) = "11"  
countAndSay(3) = "21"  
countAndSay(4) = "1211"

---

### Constraints

- `1 <= n <= 30`

