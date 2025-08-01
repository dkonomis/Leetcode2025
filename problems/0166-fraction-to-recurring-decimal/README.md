# 0166. Fraction to Recurring Decimal

**Difficulty**: Medium

**Link**: LeetCode 166

---

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than `10⁴` for all the given inputs.

**Example 1:**

    **Input**: numerator = 1, denominator = 2
    **Output**: "0.5"

**Example 2:**

    **Input**: numerator = 2, denominator = 1
    **Output**: "2"

**Example 3:**

    **Input**: numerator = 4, denominator = 333
    **Output**: "0.(012)"

**Constraints:**

- `-2³¹ <= numerator, denominator <= 2³¹ - 1`
- `denominator != 0`
