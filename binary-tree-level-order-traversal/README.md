# 102. Binary Tree Level Order Traversal

## Difficulty

Medium

## Question

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

**Example 1:**

    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

**Example 2:**

    Input: root = [1]
    Output: [[1]]

**Example 3:**

    Input: root = []
    Output: []

**Constraints:**

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

## Link

[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Solution

Solution implements queue to address each level separately and stores current level index in a pair.
