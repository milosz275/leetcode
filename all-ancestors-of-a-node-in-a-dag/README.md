# 2192. All Ancestors of a Node in a Directed Acyclic Graph

## Difficulty

Medium

## Question

You are given a positive integer `n` representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from `0` to `n - 1`.

You are also given a 2D integer array `edges` where `edges[i] = [from_i, to_i]` denotes that there is a unidirectional edge `from_i` to `to_i` in the graph.

Return a list `answer`, where `answer[i]` is a list of ancestors of the `i-th` node, sorted in ascending order.

A node `u` is an ancestor of another node `v` if `u` can reach `v` via a set of edges.

**Example:**

```
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
```

[![Example 1](assets/graph.png)]

## Link

[All Ancestors of a Node in a Directed Acyclic Graph](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)
