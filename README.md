# leetcode

##Dynamic Programming

### 664

### 650

#### 题目

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

思路是$dp[n] = min_i dp[n/i]+i\ if\ i | n$
但是讨论区里面有个答案是最小的整除的i就是最优的
解释是
- It take 2 op to double, 3 ops to triple
- if n % 2 == 0, then f(n) = f(n/2) + 2
- if n % 3 == 0, then f(n) = f(n/3) + 3
- 2 * 2 = 2 + 2, 2 * 3 > 2 + 3, 4 * 4 > 4 + 4, so it is always better to divide whenever possible
- now it became a problem for finding all possible factors


