# 0298. Binary Tree Longest Consecutive Sequence

**Difficulty**: Medium

**Link**: LeetCode 298

---

Given the `root` of a binary tree, return *the length of the longest consecutive sequence path*.

A consecutive sequence path is a path where the values increase by one along the path.

Note that the path can start **at any node** in the tree, and you cannot go from a node to its parent in the path.

**Example 1:**

         1
          \
           3
          / \
         2   4
              \
               5

    **Input:** root = [1,null,3,2,4,null,null,null,5]
    **Output:** 3
    **Explanation:** Longest consecutive sequence path is 3-4-5, so return 3.

**Example 2:**

         2
          \
           3
          /
         2
        /
       1

    **Input:** root = [2,null,3,2,null,1]
    **Output:** 2
    **Explanation:** Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3 * 10^4]`.
- `-3 * 10^4 <= Node.val <= 3 * 10^4`
