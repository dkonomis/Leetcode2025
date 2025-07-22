# 0170. Two Sum III - Data Structure Design

**Difficulty**: Easy

**Link**: LeetCode 170

---

Design and implement a TwoSum class. It should support the following operations: `add` and `find`.

- `add` - Add the number to an internal data structure.
- `find` - Find if there exists any pair of numbers which sum is equal to the value.

**Example 1:**

    TwoSum twoSum = new TwoSum();
    twoSum.add(1);   // [] --> [1]
    twoSum.add(3);   // [1] --> [1,3]
    twoSum.add(5);   // [1,3] --> [1,3,5]
    twoSum.find(4);  // 1 + 3 = 4, return true
    twoSum.find(7);  // No two integers sum up to 7, return false

**Constraints:**

- `-10⁵ <= number <= 10⁵`
- `-2³¹ <= value <= 2³¹ - 1`
- At most `10⁴` calls will be made to `add` and `find`.
