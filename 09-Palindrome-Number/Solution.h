#include <string>
using std::string;

class Solution {
public:
    bool isPalindrome(int x) {
        string a = std::to_string(x), b = std::to_string(x);
        reverse(a.begin(), a.end());

        return a==b;
    }

    // 先定义一个reverseNum
    bool isPalindrome2(int x) {
        // corner case
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int reverseNum = 0;
        while (reverseNum < x) {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNum || x == reverseNum / 10;
    }
};