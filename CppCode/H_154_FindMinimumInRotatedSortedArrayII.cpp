#include "lc_header.h"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
private:
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nums[left];
        int mid = left + (right - left)/2;
        int m = nums[mid], l = nums[left], r = nums[right];
        if (l < r) {
            return l;
        } else if (m <= r && m < nums[mid-1]) {
            return m;
        } else if (m > r) {
            return helper(nums, mid+1, right);
        } else if (m < l) {
            return helper(nums, left, mid-1);
        } else {
            return min(helper(nums, mid+1, right), helper(nums, left, mid-1));
        }
    }
};