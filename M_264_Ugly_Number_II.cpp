#include "lc_header.h"
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        vector<int> factors = {2,3,5};
        vector<int> indexes(3, 0);
        vector<int> values(3, 1);
        vector<int> ugly_numbers(n, 1);
        int next_val;
        for (size_t i = 1; i < n; i++) {
            next_val = INT_MAX;
            for (size_t j = 0; j < 3; j++) {
                if (ugly_numbers[i-1] == values[j]) {
                    values[j] = ugly_numbers[indexes[j]++] * factors[j];
                }
                next_val = min(next_val, values[j]);
            }
            ugly_numbers[i] = next_val;
        }
        return ugly_numbers[n-1];
    }
};