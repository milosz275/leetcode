# 148. Sort List

## Difficulty

Medium

## Question

Given the head of a linked list, return the list after sorting it in ascending order.

**Example 1:**

    Input: head = [4,2,1,3]
    Output: [1,2,3,4]

**Example 2:**

    Input: head = [-1,5,3,4,0]
    Output: [-1,0,3,4,5]

**Example 3:**

    Input: head = []
    Output: []

**Constraints:**

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105

## Link

[Sort List](https://leetcode.com/problems/sort-list/)

## Solution

Solution uses recursion, defines base case as a one element list and implements merge sort for solid O(n log n) time and O(1) space complexity.
