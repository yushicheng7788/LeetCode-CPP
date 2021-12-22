#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row * col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
        }
    }

private:
    int dx[4] = {-1, 0, 1, -1}, dy[4] = {0, 1, 0, -1};
};