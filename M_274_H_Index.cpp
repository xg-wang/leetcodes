#include "lc_header.h"
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() < 1) return 0;
        if (citations.size() < 2) return citations[0] >= 1 ? 1 : 0;
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int n_h = n / 2;
        while (true) {
            if (citations[n_h-1] > n-n_h) {
                n_h--;
            } else if (citations[n_h] < n-n_h) {
                n_h++;
            } else {
                return n - n_h;
            }
        }
    }
};