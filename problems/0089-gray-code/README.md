# 0089. Gray Code

**Difficulty**: Medium  
**Link**: [https://leetcode.com/problems/gray-code](https://leetcode.com/problems/gray-code)

---

## Problem

An **n-bit gray code sequence** is a sequence of `2ⁿ` integers where:

- Every integer is in the **inclusive range** `[0, 2ⁿ - 1]`,
- The **first integer** is `0`,
- An integer appears **no more than once** in the sequence,
- The **binary representation** of every pair of **adjacent integers** differs by **exactly one bit**, and
- The **first and last** integers in the sequence also differ by **exactly one bit** (circular condition).

Given an integer `n`, return **any valid n-bit Gray code sequence**.

---

**Example 1:**

**Input:** n = 2  
**Output:** [0,1,3,2]  
**Explanation:**  
The binary representation of [0,1,3,2] is [00, 01, 11, 10]:  
- 00 and 01 differ by one bit  
- 01 and 11 differ by one bit  
- 11 and 10 differ by one bit  
- 10 and 00 differ by one bit

Another valid sequence: [0,2,3,1], which in binary is [00, 10, 11, 01]:  
- 00 and 10 differ by one bit  
- 10 and 11 differ by one bit  
- 11 and 01 differ by one bit  
- 01 and 00 differ by one bit

---

**Example 2:**

**Input:** n = 1  
**Output:** [0,1]

---

**Constraints:**

- 1 <= n <= 16

