#include "lc_header.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size()-2; i++) {
            size_t l = i+1, r = nums.size()-1;
            while (l < r) {
                //printf("i=%d, l=%d, r=%d\n", i, l, r);
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    vector<int> curr = {nums[i], nums[l], nums[r]};
                    res.push_back(curr);
                    l++; r--;
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
            }
            while (i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};