#include <iostream>
#include <string>
#include "Solution.h"

using namespace std;

int main() {
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str) << " " << s.lengthOfLongestSubstring2(str) << endl;

    return 0;
}