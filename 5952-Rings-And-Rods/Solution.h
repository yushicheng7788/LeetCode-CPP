#include <string>
#include <cstring>
using std::string;

class Solution {
public:
    int countPoints(string rings) {
        int ans = 0;
        int rods[11];
        memset(rods, 0, sizeof(rods));
        for (int i = 0; i < rings.size(); i += 2) {
            char c = rings[i];
            int num = rings[i+1] - '0';
            if (c == 'R')
                rods[num] |= 1;
            else if (c == 'G')
                rods[num] |= 2;
            else
                rods[num] |= 4;
        }
        for (int i = 0; i < 11; ++i)
            if (rods[i] == 7)
                ++ans;

        return ans;
    }
};