// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.empty()) return result;
        int min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                result = max(result, prices[i] - min);
            }
        }
        return result;
    }
};