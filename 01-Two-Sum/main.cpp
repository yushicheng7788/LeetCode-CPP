#include <bits/stdc++.h>
#include "Solution.h"

using namespace std;

int main() {
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = s.twoSum1(nums, target);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    res.clear();
    res = s.twoSum2(nums, target);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}
