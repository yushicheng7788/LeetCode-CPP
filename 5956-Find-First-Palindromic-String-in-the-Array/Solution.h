/*
 * @Author: ysc
 * @Date: 2021-12-20 17:25:41
 * @LastEditTime: 2021-12-20 17:26:45
 * @Description: 5956. Find First Palindromic String in the Array
 */
#include <bits/stdc++.h>

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto word: words) {
            string str = word;
            reverse(str.begin(), str.end())
            if (str == word)
                return word;
        }
        return "";
    }
};