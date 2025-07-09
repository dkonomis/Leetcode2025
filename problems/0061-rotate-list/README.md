# 0061. Rotate List

**Difficulty:** Medium  
**Link:** https://leetcode.com/problems/rotate-list/

---

## Problem

Given the head of a linked list, rotate the list to the right by `k` places.

Rotation means moving the last node to the front of the list repeatedly, for `k` times, effectively shifting the list nodes.

**Example 1:**

    Input: head = [1,2,3,4,5], k = 2  
    Output: [4,5,1,2,3]  
    **Explanation:** Rotate right by 1 → [5,1,2,3,4]. Rotate right by 2 → [4,5,1,2,3].

**Example 2:**

    Input: head = [0,1,2], k = 4  
    Output: [2,0,1]  
    **Explanation:** Rotate right by 1 → [2,0,1]; by 2 → [1,2,0]; by 3 → [0,1,2]; by 4 → [2,0,1].

**Constraints:**

- The number of nodes in the list is in the range `[0, 500]`.  
- `-100 ≤ Node.val ≤ 100`  
- `0 ≤ k ≤ 2 * 10⁹`

