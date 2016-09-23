#include "lc_header.h"
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;      
        int first = 0, second = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int next = first + nums[i];
            first = second;
            second = next > second ? next : second;
        }
        return first > second ? first : second;
    }
};