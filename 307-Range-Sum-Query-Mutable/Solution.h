#include <vector>

using std::vector;

// 单点更新，区间查询。使用树状数组解决。
class NumArray {
public:
    NumArray(vector<int>& nums)
        : n(nums.size()), data(nums), tree(vector<int>(n + 1)) {
            for (int i = 0; i < n; ++i)
                add(i + 1, nums[i]);
        }
    
    void update(int index, int val) {
        add(index + 1, val - data[index]);
        data[index] = val;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
private:
    int n;
    vector<int> data, tree;
    
    int lowbit(int k) {
        return k & -k;
    }
    
    void add(int x, int k) {
        for (; x <= n; x += lowbit(x))
            tree[x] += k;
    }
    
    int sum(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x))
            ans += tree[x];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */