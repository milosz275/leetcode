# 2554. Maximum Number of Integers to Choose From a Range I

## Difficulty

Medium

## Question

You are given an integer array banned and two integers `n` and `maxSum`. You are choosing some number of integers following the below rules:

    The chosen integers have to be in the range [1, n].
    Each integer can be chosen at most once.
    The chosen integers should not be in the array banned.
    The sum of the chosen integers should not exceed maxSum.

Return the maximum number of integers you can choose following the mentioned rules.

**Example:**

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.

## Link

[Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/)
