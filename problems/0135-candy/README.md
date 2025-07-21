# 0135. Candy

**Difficulty**: Hard  
**Link**: [LeetCode 135](https://leetcode.com/problems/candy/)

---

There are `n` children standing in a line. Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

* Each child must receive at least one candy.
* Children with a higher rating get more candies than their neighbors with lower ratings.

Return the minimum number of candies you need to have to distribute the candies to the children.

**Example 1:**

    Input: ratings = [1,0,2]
    Output: 5
    Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

**Example 2:**

    Input: ratings = [1,2,2]
    Output: 4
    Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    The third child gets 1 candy because it only needs to satisfy the left neighbor.

**Constraints:**

* `n == ratings.length`
* `1 <= n <= 2 * 10^4`
* `0 <= ratings[i] <= 2 * 10^4`
