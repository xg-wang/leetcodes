#include "lc_header.h"
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        return backtrack(nums, 0, sum/2);
    }
    bool backtrack(vector<int>& nums, int start, int target) {
        if (target <= 0) return target == 0;
        if (start >= nums.size()) return false;
        for (int i = start; i < nums.size(); i++) {
            if (backtrack(nums, i+1, target-nums[i])) {
                return true;
            }
        }
        return false;
    }
};