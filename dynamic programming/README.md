# Dynamic Programming

### 664. Strange Printer

### 650. 2 Keys Keyboard
> Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad  for each step:
>
> Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
>
> Paste: You can paste the characters which are copied last time.
>
> Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

思路是 dp[n] = min_i dp[n/i]+i if i | n

但是讨论区里面有个答案是最小的整除的i就是最优的

解释是
- It take 2 op to double, 3 ops to triple
- if n % 2 == 0, then f(n) = f(n/2) + 2
- if n % 3 == 0, then f(n) = f(n/3) + 3
- 2 * 2 = 2 + 2, 2 * 3 > 2 + 3, 4 * 4 > 4 + 4, so it is always better to divide whenever possible
- now it became a problem for finding all possible factors


### 647. Palindromic Substrings

> Given a string, your task is to count how many palindromic substrings in this string.
>
> The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

不用动态规划更快

```
for (int i = 0; i < n; ++i) {
    for(int j = 0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; ++j) ++res;
    for(int j = 0; i-j-1>=0 && i+j<n && s[i-j-1]==s[i+j]; ++j) ++res;
}
```

### 646. Maximum Length of Pair Chain

> You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
> Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
> Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

这题用贪心法，类比任务规划问题，完成最先结束的任务，也就是找(a, b)pair中b最小的， 超过了92%
