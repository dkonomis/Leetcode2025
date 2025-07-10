# 0095. Unique Binary Search Trees II

**Difficulty**: Medium  
**Link**: [LeetCode 95](https://leetcode.com/problems/unique-binary-search-trees-ii/)

---

Given an integer n, return all the structurally unique BST's (binary search trees), which have exactly n nodes of unique values from 1 to n. You may return the answer in any order.

**Example 1:**  
    **Input:** n = 3  
    **Output:**  
    [  
      [1,null,3,2],  
      [3,2,null,1],  
      [3,1,null,null,2],  
      [2,1,3],  
      [1,null,2,null,3]  
    ]  
    **Explanation:**  
        The above output represents the 5 unique BSTs shown below:  
        
            1         3     3      2      1  
             \       /     /      / \      \  
              3     2     1      1   3      2  
             /     /       \                 \  
            2     1         2                 3  

**Example 2:**  
    **Input:** n = 1  
    **Output:** [[1]]

**Constraints:**  
- `0 <= n <= 8`

