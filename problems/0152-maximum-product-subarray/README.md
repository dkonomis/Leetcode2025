# 0152. Maximum Product Subarray

**Difficulty**: Medium  
**Link**: [LeetCode 152](https://leetcode.com/problems/maximum-product-subarray/)

---

Given an integer array `nums`, find a **subarray** that has the largest product, and return _the product_.

The test cases are generated so that the answer will fit in a **32-bit** integer.

**Example 1:**

    **Input**: nums = [2,3,-2,4]
    **Output**: 6
    **Explanation**: [2,3] has the largest product 6.

**Example 2:**

    **Input**: nums = [-2,0,-1]
    **Output**: 0
    **Explanation**: The result cannot be 2, because [-2,-1] is not a subarray.

**Constraints:**

* `1 <= nums.length <= 2 * 10^4`
* `-10 <= nums[i] <= 10`
* The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.
