/*
 * @Author: ysc
 * @Date: 2021-12-21 10:29:38
 * @LastEditTime: 2021-12-21 10:32:28
 * @Description: 2111. 使数组 K 递增的最少操作次数
 */
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> v;
            for (int j = i; j < n; j += k)
                v.push_back(arr[j]);
            ans += LIS(v);
        }
        return n - ans;
    }

private:
    int LIS(vector<int> &arr) {
        vector<int> dp;
        for (auto &i: arr) {
            auto it = upper_bound(dp.begin(), dp.end(), i);
            if (it == dp.end())
                dp.push_back(i);
            else
                *it = i;
        }
        return dp.size();
    }
};