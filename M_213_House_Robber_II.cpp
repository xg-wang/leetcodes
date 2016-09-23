#include "lc_header.h"
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        if (nums.size() < 2) return nums[0];

        int first = 0, second = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            int next = first + nums[i];
            first = second;
            second = next > second ? next : second;
        }
        int first_max = first > second ? first : second;
        
        first = 0, second = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            int next = first + nums[i];
            first = second;
            second = next > second ? next : second;
        }
        int second_max = first > second ? first : second;

        return first_max > second_max ? first_max : second_max;
    }
};