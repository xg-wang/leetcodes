#include "lc_header.h"
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() < 1) return 0;
        int prevMins[3], currMins[3];
        for (auto& c: costs) {
            currMins[0] = c[0] + min(prevMins[1], prevMins[2]);
            currMins[1] = c[1] + min(prevMins[0], prevMins[2]);
            currMins[2] = c[2] + min(prevMins[0], prevMins[1]);
            copy(currMins, currMins+3, prevMins);
        }
        return min(currMins[0], min(currMins[1], currMins[2]));
    }
};