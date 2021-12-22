<!--
 * @Author: ysc
 * @Date: 2021-12-21 10:34:04
 * @LastEditTime: 2021-12-22 10:36:44
 * @Description: file content
-->
# 2104. Sum of Subarray Ranges
## 题目大意
子数组范围定义为子数组中最大值与最小值之差，请你计算所有的子数组范围和。

## Solution
数据量较小，暴力。

如果数据量较大，则此题应该为困难题。参考leetcode 907.子数组的最小值之和。统计每个数字作为最大值和最小值能够影响的范围。