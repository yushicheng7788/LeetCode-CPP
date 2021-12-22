/*
 * @Author: ysc
 * @Date: 2021-12-21 10:15:15
 * @LastEditTime: 2021-12-21 10:17:22
 * @Description: 2110. 股票平滑下跌阶段的数目
 */
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        int n = prices.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            if (prices[i] == prices[i - 1] - 1)
                dp[i] += dp[i-1];
            ans += dp[i];
        }
        return ans;
    }
};