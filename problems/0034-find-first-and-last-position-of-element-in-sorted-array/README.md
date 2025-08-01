# 0034. Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium  
**Link:** [https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array)

---

### Problem

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with **O(log n)** runtime complexity.

---

### Example 1

**Input:**  
nums = [5,7,7,8,8,10], target = 8

**Output:**  
[3,4]

---

### Example 2

**Input:**  
nums = [5,7,7,8,8,10], target = 6

**Output:**  
[-1,-1]

---

### Example 3

**Input:**  
nums = [], target = 0

**Output:**  
[-1,-1]

---

### Constraints

- `0 <= nums.length <= 10⁵`  
- `-10⁹ <= nums[i] <= 10⁹`  
- `nums` is a non-decreasing array.  
- `-10⁹ <= target <= 10⁹`

