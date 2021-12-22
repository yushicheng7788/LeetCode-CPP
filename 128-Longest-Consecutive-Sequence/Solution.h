#include <vector>
#include <unordered_set>
#include <algorithm>
using std::vector;
using std::unordered_set;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> uset(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (!uset.count(nums[i] - 1)) {
                int temp = 0;
                while (uset.count(nums[i] + 1)) {
                    ++temp;
                    ++nums[i];
                }
                ans = std::max(ans, temp);
            }
        }
        return ans;
    }
};