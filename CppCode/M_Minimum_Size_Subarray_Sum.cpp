#include "lc_header.h"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, start = 0, min_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                min_len = min(min_len, i-start+1);
                sum -= nums[start++];
            }
        }
        return min_len;
    }
};