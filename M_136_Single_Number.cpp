// https://leetcode.com/problems/single-number/
#include "lc_header.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            result ^= *it;
        }
        return result;
    }
};