# 题目大意
Given an integer array nums, return the length of the longest strictly increasing subsequence.
# 解题思路
* 动态规划。
令 $dp[i]$ 表示以 $nums[i]$ 结尾的最长上升递增子序列长度。则状态转移方程为 $dp[i] = max(dp[j]), j < i \cap nums[j] < nums[i]$。时间复杂度为 $O(n^{2})$。

* 贪心+二分搜索
https://www.acwing.com/solution/content/287/