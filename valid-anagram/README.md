# 242. Valid Anagram

## Difficulty

Easy

## Question

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

**Example 1:**

Input: s = "anagram", t = "nagaram"
Output: true

**Example 2:**

Input: s = "rat", t = "car"
Output: false

**Constraints:**

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

## Link

[Valid Anagram](https://leetcode.com/problems/valid-anagram/)

## Solution

Solution works for Unicode characters, but creates some overhead comparing for simple ASCII solutions. It implements hash map to count character occurrences for resource usage minimization. Whole time complexity is O(n).
