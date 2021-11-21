#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // brute force
    vector<int> twoSum1(vector<int>& nums, int target) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }

    // using hash table
    vector<int> twoSum2(vector<int> &nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            umap.insert({nums[i], i});
        }
        return {};
    }
};
