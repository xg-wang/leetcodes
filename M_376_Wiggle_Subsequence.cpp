#include "lc_header.h"
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        if (nums.size() == 1) return 1;
        
        int last_diff = nums[1] - nums[0];
        int count = 0;
        size_t i = 1;
        while (i < nums.size() && nums[i] - nums[i-1] == 0) {
            i++;
        }
        if (i < nums.size()) {
            count = 1;
            last_diff = nums[i] - nums[i-1];
        }
        int curr_diff = 0;
        for (; i < nums.size(); i++){
            curr_diff = nums[i] - nums[i-1];
            if ((curr_diff>=0 && last_diff>0) || (curr_diff<=0 && last_diff<0)) {
                last_diff += curr_diff;
            } else {
                last_diff = curr_diff;
                count++;
            }
        }
        return count + 1;
    }
    
};