#include "lc_header.h"
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, max_len = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //cout << sum << endl;
            if (m.count(sum-k)) {
                max_len = max(max_len, i - m[sum-k]);
            }
            if (!m.count(sum)) {
                m[sum] = i;   
            }
        }
        return max_len;
    }
};