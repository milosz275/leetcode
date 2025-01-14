# 933. Number of Recent Calls

## Difficulty

Easy

## Question

You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

    RecentCounter() Initializes the counter with zero recent requests.
    int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].

It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

**Constraints:**

    1 <= t <= 109
    Each test case will call ping with strictly increasing values of t.
    At most 104 calls will be made to ping.

## Link

[Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/)

## Solution

Solution utilizes queue to track t elements, such that t - 3000.
