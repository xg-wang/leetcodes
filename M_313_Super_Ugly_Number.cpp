#include "lc_header.h"

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly_numbers(n, INT_MAX);
        vector<int> idxs(primes.size(), 0);
        vector<int> vals(primes.size(), 1);
        int next_val = 1;
        
        for (int i = 0; i < n; i++) {
            ugly_numbers[i] = next_val;
            next_val = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                if (vals[j] == ugly_numbers[i]) {
                    vals[j] = ugly_numbers[idxs[j]++] * primes[j];
                }
                next_val = min(vals[j], next_val);
            }
        }
        
        return ugly_numbers[n-1];
    }
};