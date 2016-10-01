#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> results;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitset<10>((m << 4) | h).count() == num) {
                    results.push_back(to_string(h) + (m<10?":0":":") + to_string(m));
                }
            }
        }
        return results;
    }
};