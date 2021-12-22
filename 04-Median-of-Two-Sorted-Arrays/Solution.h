#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot & 1) {
            return findKthNumber(nums1, 0, nums2, 0, tot / 2 + 1);
        } else {
            int left = findKthNumber(nums1, 0, nums2, 0, tot / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, tot / 2 + 1);
            return (left + right) / 2.0;
        }
    }
private:
    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        if (nums1.size() - i > nums2.size() - j)
            return findKthNumber(nums2, j, nums1, i, k);
        if (nums1.size() == i)
            return nums2[j + k - 1];
        if (k == 1) {
            return std::min(nums1[i], nums2[j]);
        }
        int si = std::min((int)nums1.size(), i + k / 2), sj = j + k / 2;
        if (nums1[si - 1] < nums2[sj - 1])
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        else
            return findKthNumber(nums1, i, nums2, sj, k - (sj - j));
    }
};