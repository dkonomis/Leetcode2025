# 0008. String to Integer (atoi)

**Difficulty**: Medium  
**Link**: [LeetCode 8](https://leetcode.com/problems/string-to-integer-atoi/)

---

## Problem

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to the C/C++ `atoi` function).

The algorithm follows these steps:

1. Read in and ignore any leading whitespace.
2. Check if the next character is '+' or '-' and record the sign.
3. Read in next characters until the next non-digit character or end of input is reached. The digits are the integer part.
4. Convert those digits into an integer.
5. Clamp the integer if it is out of the 32-bit signed integer range:  
   - If the number is less than `-2³¹`, return `-2³¹`.  
   - If the number is more than `2³¹ - 1`, return `2³¹ - 1`.

The function returns the integer formed or `0` if no valid conversion could be performed.

---

### **Example 1**

**Input:**  
    s = "42"  
**Output:**  
    42

---

### **Example 2**

**Input:**  
    s = "   -42"  
**Output:**  
    -42  
**Explanation:**  
    The function skips leading whitespace, reads '-', then reads 42.

---

### **Example 3**

**Input:**  
    s = "4193 with words"  
**Output:**  
    419  
**Explanation:**  
    Conversion stops at the first non-digit character.

---

### **Example 4**

**Input:**  
    s = "words and 987"  
**Output:**  
    0  
**Explanation:**  
    The first non-whitespace character is not a valid digit or sign.

---

### **Example 5**

**Input:**  
    s = "-91283472332"  
**Output:**  
    -2147483648  
**Explanation:**  
    The number is less than `-2³¹`, so it is clamped.

---

### **Constraints**

- `0 <= s.length <= 200`
- `s` consists of English letters, digits, `' '`, `'+'`, `'-'`, and other printable ASCII characters.

