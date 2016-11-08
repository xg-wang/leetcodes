#include "lc_header.h"
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            int l = nums[left], m = nums[mid], r = nums[right];
            if (m == target) return mid;
            if (l <= m) {
                if (target <= m && target >= l) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (target >= m && target <= r) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};