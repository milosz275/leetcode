# 234. Palindrome Linked List

## Difficulty

Easy

## Question

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

**Example 1:**

    Input: head = [1,2,2,1]
    Output: true

**Example 2:**

    Input: head = [1,2]
    Output: false

**Constraints:**

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

## Link

[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

## Solution

Solution loads pointers to list nodes into double-ended queue. Then, it compares both top and bottom values at once to establish whether the input is in fact a palindrome.

- Time complexity: O(n)
- Space complexity: O(1)
