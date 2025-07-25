# 0015. 3Sum

**Difficulty**: Medium  
**Link**: [https://leetcode.com/problems/3sum](https://leetcode.com/problems/3sum)

---

## Problem

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`, and
- `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must **not contain duplicate triplets**.

---

### Example 1

**Input:**  
    nums = [-1, 0, 1, 2, -1, -4]

**Output:**  
    [[-1, -1, 2], [-1, 0, 1]]

---

### Example 2

**Input:**  
    nums = [0, 1, 1]

**Output:**  
    []

---

### Example 3

**Input:**  
    nums = [0, 0, 0]

**Output:**  
    [[0, 0, 0]]

---

## Constraints

- 3 <= nums.length <= 3000  
- -10⁵ <= nums[i] <= 10⁵

