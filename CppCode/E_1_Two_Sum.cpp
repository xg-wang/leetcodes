#include "lc_header.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> backup = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum > target) {
                right--;
            } else if (sum < target){
                left++;
            } else {
                break;
            }
        }
        int left_value = nums[left];
        int right_value = nums[right];
        for (int i = 0; i < nums.size(); ++i) {
            if (backup[i] == left_value) {
                left = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (backup[i] == right_value) {
                right = i;
                break;
            }
        }
        return {left, right};
    }
};