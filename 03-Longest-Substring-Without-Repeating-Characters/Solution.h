#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    // sliding windows
    int lengthOfLongestSubstring(std::string s) {
        // 使用unordered_set记录每个字符是否出现
        std::unordered_set<char> uset;
        int ans = 0;
        
        // i是窗口的右边界，j是窗口的左边界
        for (int i = 0, j = 0; i < s.size(); ++i) {
            while (uset.find(s[i]) != uset.end()) {     // 说明出现重复字符了
                uset.erase(s[j++]);
            }
            uset.insert(s[i]);
            ans = std::max(ans, i - j + 1);
        }
        return ans;
    }

    int lengthOfLongestSubstring2(std::string s) {
        if (s.empty())
            return 0;
        // dp[i]表示以s[i]为结尾的最长无重复子串长度
        std::vector<int> dp(s.size(), 1);
        int ans = 1;
        for (int i = 1; i < s.size(); ++i) {
            int j = i-1;
            for (; j >= i - dp[i - 1]; --j)
                if (s[i] == s[j])
                    break;
            dp[i] = i - j;
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};