#include <iostream>
#include "Solution.h"

using namespace std;

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;

    int ans1 = s.lengthOfLIS(nums);
    int ans2 = s.lengthOfLIS2(nums);

    cout << ans1 << " " << ans2 << endl;
    return 0;
}