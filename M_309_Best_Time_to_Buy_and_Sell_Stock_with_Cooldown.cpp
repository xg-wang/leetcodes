/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 * DP solution:
 * buy[i]  = max(rest[i-1]-price, buy[i-1])
 * sell[i] = max(buy[i-1]+price, sell[i-1])
 * rest[i] = max(sell[i-1], buy[i-1], rest[i-1])
 */
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        if (n == 2) return prices[1] > prices[0] ? prices[1] - prices[0] : 0;

        int buy         = -prices.front();
        int prev_buy;
        int sell        = 0;
        int prev_sell   = 0;

        for (size_t i = 0; i < n; i++) {
            int v = prices[i];
            prev_buy = buy;
            buy = max(prev_buy, prev_sell - v);
            prev_sell = sell;
            sell = max(prev_sell, prev_buy + v);
        }

        return max(buy, sell);
    }
};

int main() {
    Solution sol;
    vector<int> in1 = {6,1,3,2,4,7}; // 6
    vector<int> in2 = {1,2,3,0,2}; // 3
    vector<int> in3 = {2,1,2,0,1}; // 1


    cout << sol.maxProfit(in1) << endl;
    cout << sol.maxProfit(in2) << endl;
    cout << sol.maxProfit(in3) << endl;
}
