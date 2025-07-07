# 0045. Jump Game II

**Difficulty:** Medium  
**Link:** [https://leetcode.com/problems/jump-game-ii](https://leetcode.com/problems/jump-game-ii)

---

### Problem

You are given a **0-indexed** array of integers `nums` of length `n`. Each element in the array represents your maximum jump length at that position.

Return *the minimum number of jumps to reach* `nums[n - 1]`.  
The test cases are generated such that you **can reach** `nums[n - 1]`.

---

### Example 1

**Input:**  
    nums = [2,3,1,1,4]  
**Output:**  
    2

**Explanation:**  
The minimum number of jumps to reach the last index is 2.  
Jump 1 step from index 0 to 1, then 3 steps to the last index.

---

### Example 2

**Input:**  
    nums = [2,3,0,1,4]  
**Output:**  
    2

---

### Constraints

- `1 <= nums.length <= 10⁴`  
- `0 <= nums[i] <= 1000`  
- It is guaranteed that you can reach the last index.

