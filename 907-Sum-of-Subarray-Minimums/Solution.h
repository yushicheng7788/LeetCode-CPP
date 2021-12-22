/*
 * @Author: ysc
 * @Date: 2021-12-22 09:43:14
 * @LastEditTime: 2021-12-22 10:06:59
 * @Description: 907. 子数组的最小值之和
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i])
                stk.pop();
            if (stk.empty())
                l[i] = -1;
            else
                l[i] = stk.top();
            stk.push(i);
        }
        
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if (stk.empty())
                r[i] = n;
            else
                r[i] = stk.top();
            stk.push(i);
        }
        long long res = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)arr[i] * (i - l[i]) * (r[i] - i)) % MOD;
        }
        return res;
    }
};