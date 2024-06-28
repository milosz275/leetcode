# 327. Count of Range Sum

## Difficulty

Hard

**Remark:**

This solution is correct but not time efficient. It only passes 54/67 test cases.

## Question

Given an integer array `nums`, and two integers `lower` and `upper`, return the number of range sums that lie in `[lower, upper]` inclusive.

Range sum `S(i, j)` is defined as the sum of the elements in `nums` between indices `i` and `j` inclusive, where (`i ≤ j`).

**Note:**

A naive algorithm of O(n2) is trivial. You MUST do better than that.

**Example:**

```
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
```

## Link

[Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)
