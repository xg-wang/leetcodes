#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if (n <= 0) return res;
        res.push_back(1);
        if (n == 1) return res;
        int base = 1;
        for (int i = 2; i <= n; i++) {
            base *= 2;
            int curr_size = res.size();
            for (int idx = curr_size - 1; idx >= 0; idx--) {
                res.push_back(base + res[idx]);
            }
        }
        return res;
    }
};