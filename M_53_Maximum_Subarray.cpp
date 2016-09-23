#include "lc_header.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) {
            return 0;
        }
        int global_max = nums[0];
        int curr_max = nums[0];
        int idx = 0;
        while (nums[idx] < 0 && idx < len) {
            curr_max = max(curr_max, nums[idx++]);
        }
        global_max = curr_max;
        curr_max = 0;
        while (idx < len) {
            while (idx < len && curr_max >= 0) {
                curr_max += nums[idx++];
                global_max = max(global_max, curr_max);
            }
            curr_max = 0;
        }
        return global_max;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> in = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(in) << endl;
    return 0;
}