# 0098. Validate Binary Search Tree

**Difficulty**: Medium  
**Link**: [LeetCode 98](https://leetcode.com/problems/validate-binary-search-tree/)

---

Given the `root` of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

- The left subtree of a node contains only nodes with keys **strictly less** than the node’s key.
- The right subtree of a node contains only nodes with keys **strictly greater** than the node’s key.
- Both the left and right subtrees must also be binary search trees.

**Example 1:**  
    **Input:** root = [2,1,3]  
    **Output:** true

**Example 2:**  
    **Input:** root = [5,1,4,null,null,3,6]  
    **Output:** false  
    **Explanation:** The root’s right child has value 4 which is not > 5.

**Constraints:**  
- The number of nodes in the tree is in the range `[1, 10⁴]`.  
- `-2³¹ <= Node.val <= 2³¹ - 1`

