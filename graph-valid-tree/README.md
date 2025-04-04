# Graph Valid Tree

## Difficulty

Medium

## Question

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

**Example 1:**

    Input:
    n = 5
    edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

    Output:
    true

**Example 2:**

    Input:
    n = 5
    edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]

    Output:
    false

**Constraints:**

    1 <= n <= 100
    0 <= edges.length <= n * (n - 1) / 2

## Link

[Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)

## Solution

Solution uses stack to implement iterative DFS for checking if the graph is a valid tree.
