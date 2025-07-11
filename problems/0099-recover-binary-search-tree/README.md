# 0099. Recover Binary Search Tree

**Difficulty**: Hard  
**Link**: [LeetCode 99](https://leetcode.com/problems/recover-binary-search-tree/)

---

You are given the `root` of a binary search tree (BST), where exactly two nodes have been swapped by mistake.  
Recover the tree without changing its structure.

**Example 1:**  
    **Input:** root = [1,3,null,null,2]  
    **Output:** [3,1,null,null,2]  
    **Explanation:** 3 and 1 were swapped.

**Example 2:**  
    **Input:** root = [3,1,4,null,null,2]  
    **Output:** [2,1,4,null,null,3]  
    **Explanation:** 2 and 3 were swapped.

**Constraints:**  
- The number of nodes in the tree is in the range `[2, 1000]`.  
- `-2³¹ <= Node.val <= 2³¹ - 1`  

**Follow-up:**  
A solution using `O(n)` space is pretty straightforward.  
Could you devise a solution using **constant space** (i.e., O(1) space, excluding the recursion stack)?

