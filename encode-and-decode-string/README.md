# 659. Encode and Decode String

## Difficulty

Medium

## Question

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Please implement encode and decode

**Example 1:**

    Input: ["lint","code","love","you"]

    Output: ["lint","code","love","you"]

    Explanation:

    One possible encode method is: "lint:;code:;love:;you"

**Example 2:**

    Input: ["we", "say", ":", "yes"]

    Output: ["we", "say", ":", "yes"]

    Explanation:

    One possible encode method is: "we:;say:;:::;yes"

## Link

[Encode and Decode String](https://leetcode.com/problems/encode-and-decode-string/)

## Solution

Solution uses given example as a base for encoding with `:;` sequence.
