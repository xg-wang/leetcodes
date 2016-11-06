// https://leetcode.com/problems/happy-number/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> history;
        int val = n;
        while (val != 1) {
            if (history.find(val) != history.end()) return false;
            history.insert(val);
            int new_val = 0;
            while (val != 0) {
                new_val += pow(val % 10, 2);
                val /= 10;
            }
            val = new_val;
        }
        return true;
    }
};

