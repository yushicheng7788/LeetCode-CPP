#include <climits>

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            if (x > 0 && ans > (INT_MAX - x % 10) / 10)     // ans * 10 + x % 10 > INT_MAX，则溢出，但是不能够直接乘以10
                return INT_MAX;
            if (x < 0 && ans < (INT_MIN - x % 10) / 10)
                return INT_MIN;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};