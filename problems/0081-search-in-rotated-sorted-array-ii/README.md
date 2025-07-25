# 0081. Search in Rotated Sorted Array II

**Difficulty**: Medium  
**Link**: [LeetCode 81](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

---

## Problem

There is an integer array `nums` sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (0 <= k < nums.length) such that the resulting array is  
`[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed).  
For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index `5` and become `[4,5,6,6,7,0,1,2,4,4]`.

Given the array `nums` **after the rotation** and an integer `target`, return `true` *if* `target` *is in* `nums`, or `false` *if it is not in* `nums`.

You must decrease the overall time complexity as much as possible.

---

### Example 1

**Input:**  
`nums = [2,5,6,0,0,1,2], target = 0`  
**Output:**  
`true`

---

### Example 2

**Input:**  
`nums = [2,5,6,0,0,1,2], target = 3`  
**Output:**  
`false`

---

### Constraints

- `1 <= nums.length <= 5000`  
- `-10⁴ <= nums[i] <= 10⁴`  
- `nums` is guaranteed to be a rotated array.  
- `-10⁴ <= target <= 10⁴`

---

### Follow-up

This problem is similar to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/), but `nums` may contain duplicates.  
Would this affect the run-time complexity? How and why?

