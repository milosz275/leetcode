# 258. Add Digits

## Difficulty

Easy

## Question

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

**Example 1:**

    Input: num = 38
    Output: 2
    Explanation: The process is
    38 --> 3 + 8 --> 11
    11 --> 1 + 1 --> 2
    Since 2 has only one digit, return it.

**Example 2:**

    Input: num = 0
    Output: 0

**Constraints:**

    0 <= num <= 2^31 - 1

## Link

[Add Digits](https://leetcode.com/problems/add-digits/)

## Solution

Solution is O(1) using [digital root](https://en.wikipedia.org/wiki/Digital_root) property of specified digit sum problem.
