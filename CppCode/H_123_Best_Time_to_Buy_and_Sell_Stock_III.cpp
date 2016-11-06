// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (n < 3) return prices.back() > prices.front() ? prices.back() - prices.front() : 0;

        int maxr = prices.back();
        int curr_maxr = 0;
        vector<int> rr(n, 0);
        for (int j = n - 1; j > 0; j--) {
            if (prices[j] > maxr) {
                maxr = prices[j];
            } else {
                curr_maxr = max(curr_maxr, maxr - prices[j]);
            }
            rr[j] = curr_maxr;
        }

        int rl = 0;
        int ret = 0;
        int minl = prices.front();
        for (int i = 1; i < n; i++) {
            if (prices[i] < minl) {
                minl = prices[i];
            } else {
                rl = max(rl, prices[i] - minl);
            }
            ret = max(ret, rl + rr[i]);
        }

        return ret;
    }

    int maxProfit_exceeds_time(vector<int>& prices) {
        if (prices.empty()) return 0;
        int rl = 0;
        int ret = 0;
        int minl = prices.front();

        int n = prices.size();
        if (n < 3) return prices.back() > minl ? prices.back() - minl : 0;

        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[i-1]) {
                if (prices[i] < minl) {
                    minl = prices[i];
                }
                int rr = 0;
                int maxr = prices.back();
                for (int j = n - 2; j >= i; --j) {
                    if (prices[j] > maxr) {
                        maxr = prices[j];
                    } else {
                        rr = max(rr, maxr - prices[j]);
                    }
                }
                ret = max(ret, rl + rr);
            } else {
                rl = max(rl, prices[i] - minl);
                ret = max(ret, rl);
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> in1 = {6,1,3,2,4,7};
    vector<int> in2 = {1,2,4};
    vector<int> in3 = {4,2,1};

    cout << sol.maxProfit(in1) << endl;
    cout << sol.maxProfit(in2) << endl;
    cout << sol.maxProfit(in3) << endl;
}
