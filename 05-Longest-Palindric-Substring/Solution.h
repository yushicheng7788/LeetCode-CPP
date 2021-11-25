#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    // Brute Force
    // Time Limit Exceeded.
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 1; i + j <= s.size(); ++j) {
                string temp = s.substr(i, j);
                if (isPalindromic(temp) && temp.size() > ans.size())
                    ans = temp;
            }
        }
        return ans;
    }

    // Expand Around Center
    // Time Complexity: O(n^2)
    string longestPalindrome2(string s) {
        int st = 0, ed = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > ed - st) {
                st = left1;
                ed = right1;
            }
            if (right2 - left2 > ed - st) {
                st = left2;
                ed = right2;
            }
        }
        return s.substr(st, ed - st + 1);
    }

    // manacher
    // 记录臂长
    string longestPalindrome3(string s) {
        // 预处理
        string t = "#";
        for (auto &c : s) {
            t += c;
            t += '#';
        }
        s = t;

        int st = -1, ed = -1;
        vector<int> arm_len;

        int right = -1, j = -1;
        for (int i = 0; i < s.size(); ++i) {
            int cur_arm_len = 0;
            if (right >= i) {
                int i_symm = j * 2 - i;
                int min_arm_len = std::min(right - i, arm_len[i_symm]);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            } else {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right) {
                right = i + cur_arm_len;
                j = i;
            }
            if (2 * cur_arm_len + 1 > ed - st + 1) {
                st = i - cur_arm_len;
                ed = i + cur_arm_len;
            }
        }
        string ans;
        for (int i = st; i <= ed; ++i) {
            if (s[i] != '#')
                ans += s[i];
        }
        return ans;    
    }

    // dynamic programming
    string longestPalindrome4(string s) {
        // dp[i][j] means s[i]~s[j] is palindromic or not.
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
        // dp[i][i] = 1;
        const int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxlen = 0, idx = -1;
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                if (len == 0)
                    dp[i][j] = true;
                else if (len == 1)
                    dp[i][j] = s[i] == s[j];
                else {
                    dp[i][j] = (dp[i+1][j-1]) && (s[i] == s[j]);
                }
                if (dp[i][j] && len >= maxlen) {
                    idx = i;
                    maxlen = len;
                }
            }
        }
        return s.substr(idx, maxlen + 1);
    }

private:
    bool isPalindromic(const string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
            

        return true;
    }

    std::pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right > s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    int expand(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // return (right - 1 - (left + 1) + 1 - 1) / 2;
        return (right - left - 2) / 2;
    }
};