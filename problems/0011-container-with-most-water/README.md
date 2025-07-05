# 0011. Container With Most Water

**Difficulty**: Medium  
**Link**: [LeetCode 11](https://leetcode.com/problems/container-with-most-water)

---

## Problem

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i`-th line are at `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Note**: You may not slant the container.

---

### Example 1

**Input:**  
    height = [1,8,6,2,5,4,8,3,7]  
**Output:**  
    49  
**Explanation:**  
    The pair of lines at index 1 and 8 forms the container with the maximum area.  
    The area is min(8, 7) * (8 - 1) = 7 * 7 = 49.

---

### Example 2

**Input:**  
    height = [1,1]  
**Output:**  
    1

---

## Constraints

- 2 <= height.length <= 10⁵  
- 0 <= height[i] <= 10⁴

---
