# 1161. Maximum Level Sum of a Binary Tree

## Difficulty

Medium

## Question

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.
Return the smallest level `x` such that the sum of all the values of nodes at level `x` is maximal.

**Example 1:**

    Input: root = [1,7,0,7,-8,null,null]
    Output: 2
    Explanation:
    Level 1 sum = 1.
    Level 2 sum = 7 + 0 = 7.
    Level 3 sum = 7 + -8 = -1.
    So we return the level with the maximum sum which is level 2.

**Example 2:**

    Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
    Output: 2

## Link

[Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

## Solution

Solution traverses the tree level by level using queue (BFS), keeps track of the current biggest level sum and returns the level.
