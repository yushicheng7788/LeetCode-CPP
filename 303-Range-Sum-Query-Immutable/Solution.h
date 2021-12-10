#include <vector>

using std::vector;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        preSum.resize(n+1);
        for (int i = 0; i < n; i ++)
            preSum[i+1] = preSum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }

private:
    vector<int> preSum;
};