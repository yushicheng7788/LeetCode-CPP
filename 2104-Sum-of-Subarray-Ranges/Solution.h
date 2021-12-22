/*
 * @Author: ysc
 * @Date: 2021-12-21 10:35:07
 * @LastEditTime: 2021-12-22 10:35:56
 * @Description: file content
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // long long subArrayRanges(vector<int>& nums) {
    //     long long ans = 0;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int mi = nums[i], ma = nums[i];
    //         for (int j = i + 1; j < nums.size(); ++j) {
    //             mi = min(mi, nums[j]);
    //             ma = max(ma, nums[j]);
    //             ans += ma - mi;
    //         }
    //     }
    //     return ans;
    // }

    // 单调栈 + 贡献值
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] > nums[i])
                stk.pop();
            if (stk.empty())
                l[i] = -1;
            else
                l[i] = stk.top();
            stk.push(i);
        }
        
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if (stk.empty())
                r[i] = n;
            else
                r[i] = stk.top();
            stk.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; ++i)
            res = (res - (long long)nums[i] * (i - l[i]) * (r[i] - i));
        l.clear();
        r.clear();
        stk = stack<int>();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i])
                stk.pop();
            if (stk.empty())
                l[i] = -1;
            else
                l[i] = stk.top();
            stk.push(i);
        }
        
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] <= nums[i])
                stk.pop();
            if (stk.empty())
                r[i] = n;
            else
                r[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i)
            res = (res + (long long)nums[i] * (i - l[i]) * (r[i] - i));
        return res;
    }
};