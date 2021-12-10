#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    // dynamic programming
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        int ans = 1;
        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }

    // greedy + binary search
    int lengthOfLIS2(vector<int>& nums) {
        // helper[i] 表示 最长上升子序列长度为i时最小的值
        const int n = nums.size();
        vector<int> helper(n + 1, 0);
        int len = 1;
        helper[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > helper[len]) {
                helper[++len] = nums[i];
            } else {
                int left = 1, right = len;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (helper[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (nums[i] < helper[left])
                    helper[left] = nums[i];
            }
        }
        return len;
    }
};
