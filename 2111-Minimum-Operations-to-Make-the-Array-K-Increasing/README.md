<!--
 * @Author: ysc
 * @Date: 2021-12-21 10:18:16
 * @LastEditTime: 2021-12-21 10:25:28
 * @Description: file content
-->
# 2111. Minimum Operations to Make the Array K-Increasing
## 题目大意
给定一个整数数组，请你计算出最小的操作次数，使得该数组成为k递增的。

## Solution
参考其他大佬的思路。可以发现，可以将原数组划分为若干个子数组，子数组之前互相不干扰。要想要子数组单调递增，只需要求该子数组的最长递增子序列，然后用子数组长度减去最长递增子序列的长度即为需要修改的次数。最长递增子序列可以参考leetcode300题。