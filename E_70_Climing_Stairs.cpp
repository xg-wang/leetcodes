#include "lc_header.h"
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        int prev = 1, curr = 2;
        for (int i = 2; i < n; i++) {
            curr = curr + prev;
            prev = curr - prev;
        }
        return curr;
    }
};