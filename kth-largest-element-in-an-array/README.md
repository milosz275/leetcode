# 215. Kth Largest Element in an Array

## Difficulty

Medium

## Question

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

**Example 1:**

    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

**Example 2:**

    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

**Constraints:**

    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104

## Link

[Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Solution

Solution uses priority queue, max-heap to be exact, to track kth largest element.

Time complexity of creating the heap: O(n)
Time complexity of getting kth element: O(max(n, k log n))
Space complexity: O(n)
