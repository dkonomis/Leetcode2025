# 0055. Jump Game

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/jump-game/

---

## Problem

You are given a 0-indexed array of non-negative integers `nums`. You are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.  

Return `true` if you can reach the last index, or `false` otherwise.

**Example 1:**

    Input: nums = [2,3,1,1,4]  
    Output: true  
    **Explanation:**  
    Jump 1 step from index 0 to 1, then 3 steps to the last index.

**Example 2:**

    Input: nums = [3,2,1,0,4]  
    Output: false  
    **Explanation:**  
    You will always arrive at index 3, but `nums[3] == 0`, so you cannot move further.

**Constraints:**

- `1 ≤ nums.length ≤ 10⁴`  
- `0 ≤ nums[i] ≤ 10⁵`

