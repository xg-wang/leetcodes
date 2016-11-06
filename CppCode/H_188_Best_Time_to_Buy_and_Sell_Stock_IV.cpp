// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include "lc_header.h"

using namespace std;

/**
 *  DP solution.
 *  Suppose we know max profit of all prices[n-1] for all k transactions,
 *  what would be like for prices[n] of all k transactions?
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int result = 0;

        if (k > n / 2) {
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i-1]) {
                    result += prices[i] - prices[i-1];
                }
            }
            return result;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int i = 0; i < n; i++) {
            int cur = prices[i];
            for (int j = k - 1; j > -1; j--) {
                sell[j + 1] = max(sell[j + 1], buy[j]  + cur);
                buy[j]      = max(buy[j]     , sell[j] - cur);
            }
        }

        return sell[k];
    }
};

int main() {
    Solution sol;
    vector<int> in1 = {6,1,3,2,4,7};
    vector<int> in2 = {1,2,4};


    cout << sol.maxProfit(2, in1) << endl;
    cout << sol.maxProfit(2, in2) << endl;
}
