/*
 * @Author: ysc
 * @Date: 2021-12-21 10:08:51
 * @LastEditTime: 2021-12-21 10:10:07
 * @Description: 2109. 向字符串添加空格
 */
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (i == spaces[j]) {
                res += ' ';
                ++j;
            }
            res += s[i];
        }
        return res;
    }
};