#include "lc_header.h"
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 1 || k <= 0) return false;
        set<int> sliding_window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                sliding_window.erase(nums[i-k-1]);
            }
            auto it = sliding_window.lower_bound(nums[i]-t);
            if (it != sliding_window.end() && *it - nums[i] <= t) {
                return true;
            }
            sliding_window.insert(nums[i]);
        }
        return false;
    }
};